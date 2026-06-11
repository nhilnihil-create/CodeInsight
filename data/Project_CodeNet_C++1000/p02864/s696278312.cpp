#pragma GCC optimize("O3")
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define eb emplace_back
#define ep emplace
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(vector<T> v){for(T e:v)cout<<e<<" ";cout<<endl;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}
const ll INF=1e17;
ll dp[400][400][400];
main(){
    int n=in();
    int k=in();
    vecll h;
    map<int,int> mp;
    int now=1;
    rep(i,n+1){
        if(i)h.eb(lin());
        else h.eb(0);
        mp[now++]=h.back();
    }
    rep(i,n+1)rep(j,k+1)rep(l,n+1)dp[i][j][l]=INF;
    dp[0][0][0]=0;
    rep(i,n){
        rep(j,k+1){
            rep(l,i+1){
                chmin(dp[i+1][j][i+1],dp[i][j][l]+max(0ll,h[i+1]-h[l]));
                chmin(dp[i+1][j+1][l],dp[i][j][l]);
            }
        }
    }
    ll ans=INF;
    rep(i,n+1)chmin(ans,dp[n][k][i]);
    cout<<ans;
}