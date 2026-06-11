#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<long long int>> dp;
long long int h,w;
int main(void){
  cin>>h>>w;
  grid=vector<vector<char>>(h,vector<char>(w));
  for(long long int i=0; i<h; i++){
    for(long long int j=0; j<w; j++){
      cin>>grid.at(i).at(j);
    }
  }
  dp=vector<vector<long long int>>(h,vector<long long int>(w,10000000));
  dp.at(0).at(0)=0;
  long long int pre=0;
  if(grid.at(0).at(0)=='#'){
    dp.at(0).at(0)=1;
  }
  for(long long int i=0; i<h; i++){
    for(long long int j=0; j<w; j++){
      if(i==0&&j==0){
        continue;
      }
      if(i==0){
        long long int pre=dp.at(i).at(j-1);
        if(grid.at(i).at(j-1)=='.'&&grid.at(i).at(j)=='#'){
          pre++;
        }
        dp.at(i).at(j)=pre;
      }else if(j==0){
        long long int pre=dp.at(i-1).at(j);
        if(grid.at(i-1).at(j)=='.'&&grid.at(i).at(j)=='#'){
          pre++;
        }
        dp.at(i).at(j)=pre;
      }else{
        long long int pre1=dp.at(i).at(j-1);
        if(grid.at(i).at(j-1)=='.'&&grid.at(i).at(j)=='#'){
          pre1++;
        }
        long long int pre2=dp.at(i-1).at(j);
        if(grid.at(i-1).at(j)=='.'&&grid.at(i).at(j)=='#'){
          pre2++;
        }
        dp.at(i).at(j)=min(pre1,pre2);
      }
    }
  }
  cout<<dp.at(h-1).at(w-1)<<endl;
}