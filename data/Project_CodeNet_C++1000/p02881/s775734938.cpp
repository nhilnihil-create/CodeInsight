#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define S 500005
#define M 100000000
#define nl cout<<"\n";
#define er  cout<<"\n***********\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define test lli t;  cin>>t; while(t--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (lli)(x.size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define Y cout<<"YES\n";
#define N cout<<"NO\n";
#define print(x)                 cout<<#x<<": "<<x<<endl;
#define print2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define print3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define print4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define print5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define print6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;

void solve()
{
    lli n,ans=(lli)1e16;cin>>n;
    for(lli i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans=min(ans,i+n/i-2);
        }
    }

    cout<<ans;




}


int main()
{
    fast
    #ifndef ONLINE_JUDGE
     freopen("inputa.txt", "r", stdin);
     freopen("outputa.txt", "w", stdout);
    #endif    
     
     // test
     {
          solve();
          nl
     }
}
//a+b=a?b+2?(a&b)
//__builtin_popcnt(number)
//cout<<fixed<<setprecision(8)<<output<<"\n";