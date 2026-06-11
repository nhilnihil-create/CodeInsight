#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int i=(a);i<b;i++)
#define INF 1000000000
#define MAX_N 105
using namespace std;
bool debug=false;

int dfs(int n,int i){
  int cnt=0;
  if(n==i)return 1;
  else if(i>n)return 0;
  else{
    cnt+=dfs(n,i+1);
    cnt+=dfs(n,i+2);
    cnt+=dfs(n,i+3);
    return cnt;
  }
}

int main(){
  int n;
  while(cin>>n){
    if(n==0)break;
    cout<<dfs(n,0)/3650+1<<endl;
  }
  return 0;
}