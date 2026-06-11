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
#define vec2 vector<vec>
#define vecll2 vector<vecll>
#define vec3 vector<vec2d>
#define vecll3 vector<vecll2d>
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

main(){
    int n=in();
    map<int,int> mp;
    rep(i,n){
        mp[in()]++;
    }
    vec v;
    for(auto e:mp)v.pb(e.second);
    sort(all(v));
    vec cnt(n+2);
    for(auto e:v)cnt[e]++;
    vec rui(n+2),rui2(n+2);
    rui[0]=rui2[0]=0;
    rep(i,n+1)rui[i+1]+=rui[i]+cnt[i]*i;
    rep(i,n+1)rui2[i+1]+=cnt[i]+rui2[i];
    // print(rui);
    // print(rui2);
    rep2(i,1,n){
        int l=0,r=n+1;
        while(l<r-1){
            int mid=(l+r)/2;
            int b=rui2[n+1]-rui2[mid];
            int c=rui[mid];
            if((i-b)*mid <=c)l=mid;
            else r=mid;
            // cout<<i<<" "<<mid<<" "<<b<<" "<<c<<endl;
        }
        cout<<l<<endl;
    }
}