#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
  ll s;cin >>s;
  ll inf=1000000007;
  ll dp[2020];
  rep(i,s+1)dp[i]=0;
  dp[0]=1;
  dp[1]=0;
  dp[2]=0;
  dp[3]=1;
  for(int i=4; i<s+1;i++){
    for(int j=0;j<i-2;j++){
      dp[i]+=dp[j];
      dp[i]%=inf;
    }
  }
  cout <<dp[s]<<endl;
}