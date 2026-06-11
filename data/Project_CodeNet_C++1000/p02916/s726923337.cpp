
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define fill(a,val) memset(a,val,sizeof(a))
#define REP(i,a,b) for (auto i = a; i < b; i++)
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 998244353
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define pb push_back
#define SQ(a) (a)*(a)
#define M 315
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    
    ll n;
    cin>>n;
    vector<int> a(n);
    vi b(n);
    vi c(n);
    REP(i,0,n)
    {
        cin>>a[i];
    }
    REP(i,0,n)
    {
        cin>>b[i];
    }
    REP(i,0,n-1)
    {
        cin>>c[i];
    }
    ll ans = 0;
    ans += b[a[0]-1];

    for(int i = 1;i<n;i++)
    {
        ans += b[a[i]-1];
        if(a[i-1] == a[i] - 1)
        {
            ans += c[a[i-1] - 1];
        }
    }
    cout<<ans<<endl;
}



