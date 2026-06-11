//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<sstream>
#include<cmath>
#include<set>
#include<algorithm>
#include<map>
#define mp make_pair
#define pii pair<int,int>
#pragma GCC optimize ("O3")
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-7;
const int maxn = 1e6+9;
const double pi=acos(-1.0);
const double inf = 1e17;
const int mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;++i) ans+=1ll*i*(n+1-i);
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        ans-=1ll*a*(n+1-b);
    }
    cout<<ans;
    return 0;
}
