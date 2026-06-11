#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<ll>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vecbl vector<bool>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
string stin(){string s;cin>>s;return s;}
int main(){
    int n=in(),k=in(),c=in();
    vec a(n);
    string s=stin();
    rep(i,n){
        a[i]=s[i]=='o'?1:0;
    }
    vec dp1(n),dp2(n);
    dp1[0]=a[0]==1?1:0;
    dp2[n-1]=a[n-1]==1?1:0;
    rep(i,n-1){
        if(i<c){
            dp1[i+1]=a[i]==1?1:dp1[i];
            dp2[n-i-2]=a[n-i-2]==1?1:dp2[n-i-1];
        }else{
            dp1[i+1]=a[i+1]==1?max(dp1[i-c]+1,dp1[i]):dp1[i];
            dp2[n-i-2]=a[n-i-2]==1?max(dp2[n-i-1+c]+1,dp2[n-i-1]):dp2[n-i-1];
        }
    }
    vec ans;
    rep(i,n){
        bool flag=false;
        if(a[i]==0)continue;
        if(i<1){
            if(dp2[i+1]==k-1)flag=true;
        }else if(i<n-1){
            if(dp1[i-1]+dp2[i+1]==k-1)flag=true;
        }else{
            if(dp1[i-1]==k-1)flag=true;
        }
        if(flag)ans.pb((int)(i+1));
    }
    REP(e,ans){
        cout<<e<<endl;
    }
}

