#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define _GLIBCXX_DEBUG
#define ll long long
#define rep(i,n) for (ll i = 0; i < n; i++)
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define vvl vector<vector<ll>> //a(縦行,vector<ll>(横列));
#include<algorithm>//__gcd(a,b)
#include <iostream>
#include <vector>
#include <cstdlib>
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

int main(){
    ll n;cin>>n;
    vl a(n);rep(i,n)cin>>a[i];
    vl x(n);

    ll sum=0;rep(i,n){sum+=a[i];}
    sum/=2;

    for(ll i=1;i<n;i+=2){sum-=a[i];}//x1
    x[0]=sum;cout<<2*x[0]<<endl;

    rep(i,n-1){
        x[i+1]=a[i]-x[i];
        cout<<2*x[i+1]<<endl;
    }
    



}