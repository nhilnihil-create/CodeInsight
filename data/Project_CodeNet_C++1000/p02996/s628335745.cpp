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
  ll n; cin>>n;
  /*vecrtor<ll> a(n),b(n);
  map<ll,ll> mp
  rep(i,n) [
    cin >>a[i]>>b[i];
    }*/
  vector<pair<ll,ll>> c(n);
  rep(i,n) cin >>c[i].second>>c[i].first;
  sort(all(c));
  ll sum=0;
  rep(i,n){
    sum+=c[i].second;
    if(sum>c[i].first){
      cout <<"No"<<endl;
      return 0;
    }
  }
  cout <<"Yes"<<endl;
}