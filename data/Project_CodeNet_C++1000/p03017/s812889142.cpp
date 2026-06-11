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
  ll n,a,b,c,d; cin >>n>>a>>b>>c>>d;
  string s; cin >>s;
  if(c<d){
    rep2(i,b,d-2){
      if(s[i]=='#'&&s[i+1]=='#'){
        cout <<"No"<<endl;
        return 0;
      }
    }
    rep2(i,a,c-2){
      if(s[i]=='#'&&s[i+1]=='#'){
        cout <<"No"<<endl;
        return 0;
      }
    }
    cout <<"Yes"<<endl;
  }else{
    rep2(i,b,d-2){
      if(s[i]=='#'&&s[i+1]=='#'){
        cout <<"No"<<endl;
        return 0;
      }
    }
    rep2(i,a,a-2){
      if(s[i]=='#'&&s[i+1]=='#'){
        cout <<"No"<<endl;
        return 0;
      }
    }
    rep2(i,b-2,d-1){
      if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
        cout <<"Yes"<<endl;
        return 0;
      }
    }
    cout <<"No"<<endl;
  }
}