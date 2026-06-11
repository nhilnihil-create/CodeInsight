#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define rep(i,n) for(int i=0; i < (n); i++)
#define INF 1001001
using namespace std;
 
int main(){
  int n, count=1;
  vector<string> dict;
  cin >> n;
  string s;
  int flag=0;
  rep(i,n){
    cin >> s;
    dict.push_back(s);
  }
  sort(dict.begin(), dict.end());
  rep(i,n-1){
    if(dict[i]!=dict[i+1]) count++;
  }
  cout << count << endl;
  
  
}