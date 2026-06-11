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
const ll inf = 1000000007;
int main() {
  ll n,k,s; cin >>n>>k>>s;
  vector<ll> ans(n);
  if(s>2){
  rep(i,k)ans[i]=s;
  rep2(i,k,n) ans[i]=s-1;
  rep(i,n-1)cout <<ans[i]<<" ";
  cout <<ans[n-1]<<endl;
  }else{
  rep(i,k)ans[i]=s;
  rep2(i,k,n) ans[i]=s+1;
  rep(i,n-1)cout <<ans[i]<<" ";
  cout <<ans[n-1]<<endl;
  }   
}