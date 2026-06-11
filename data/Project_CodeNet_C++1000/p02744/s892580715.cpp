#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
vector<string> x;
int n;
void dfs(string s){
  char c;
  int k=0;
  if(s.size()==n){
    x.push_back(s);
    return;
  }
  for(int i='a';i<='z';i++){
    for(int j=0;j<s.size();j++){
      if(s[j]==i){
        c=i;
        dfs(s+c);
        k=1;
        break;
      }
    }
    if(k==0){
      c=i;
      dfs(s+c);
      break;
    }
    k=0;
  }
}
int main(){
  int i;
  scanf("%d\n",&n);
  dfs("a");
  sort(x.begin(),x.end());
  for(i=0;i<x.size();i++){
    cout << x[i] << endl;
  }
  return 0;
}