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
#include <numeric>
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<int>
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

int n,k;
vecll a;

bool func(ll x){
    vecll b(n),c(n),sumB(n),sumC(n);
    rep(i,n){
        b[i]=(a[i]+x)%x;
    }
    sort(ALL(b));
    rep(i,n)c[i]=(x-b[i])%x;
    rep(i,n){
        sumB[i]=i==0?b[i]:sumB[i-1]+b[i];
        sumC[n-i-1]=i==0?c[n-i-1]:sumC[n-i]+c[n-i-1];
    }
    rep(i,n-1)if(sumB[i]==sumC[i+1] && sumC[i+1]<=k)return true;
    return false;
    
}

int main(){
    n=in();
    k=in();
    a.resize(n);
    ll sum=0,ans=0;
    rep(i,n)sum+=a[i]=in();
    for(ll x=1;x*x<=sum;x++)if(sum%x==0){
        if(func(x))ans=max(ans,x);
        if(func(sum/x))ans=max(sum/x,ans);
    }
    cout<<ans<<endl;
}
