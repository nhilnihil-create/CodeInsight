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
  string s; cin >>s;
  ll n=s.size();
  ll k; cin >>k;
  vector<ll>  v;
  vector<ll>  v2;
  ll key=1;
  ll ans=0;
  if(n==1){
    cout <<k/2<<endl;
    return 0;
  }
  rep2(i,1,n){
    if(s[i]==s[i-1]){
      key++;
      if(i==n-1){
        v.push_back(key/2);
        v2.push_back(key);
      }
    }else{
      v.push_back(key/2);
      v2.push_back(key);
      key=1;
    }
  }
  rep(i,v.size()){
    ans+=v[i];
  }
  ans*=k;
  set<char> st;
  rep(i,n)st.insert(s[i]);
  if(st.size()==1){
    cout<<(s.size()*k)/2<<endl;
    return 0;
  }
  if(s[0]==s[n-1]&&n>=3){
    if(v2[0]%2==1&&v2[v2.size()-1]%2==1){
      ans+=k-1;
    }
  }
  cout <<ans<<endl;
}