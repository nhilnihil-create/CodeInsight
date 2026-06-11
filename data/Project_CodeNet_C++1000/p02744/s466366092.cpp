#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
 int n ;
void dfs(string s,char c){//ｃは使われているマックス+1
  if(s.size()==n){
    cout<<s<<endl; //ここでn文字の文字列が決定
    }else{
     for(char d= 'a';d<=c;d++){//辞書順
       if(d==c) dfs(s+d,c+1) ;
       else dfs(s+d,c) ;
     } 
    }
  }

int main(){
   cin>>n ;
  dfs("",'a') ;
   
    return 0;
  }