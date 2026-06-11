#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define clr(a) memset(a, 0, sizeof(a))
#define set(a) memset(a, -1, sizeof(a))
#define pb push_back
#define sz(a) ((ll)a.size())
#define all(a) a.begin(), a.end()
#define mp make_pair
#define rep(i, a, y) for (ll i = a; i <= y; i++)
#define rep2(i, b) for (ll i = 0; i < b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define ppi pair<int, int>
#define scl(x) scanf("%d", &x)
#define pcl(x) printf("%d", x)
#define FastRead                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
/*
 
     ██╗██╗   ██╗██╗  ██╗ █████╗ ███╗   ██╗
     ██║██║   ██║██║  ██║██╔══██╗████╗  ██║
     ██║██║   ██║███████║███████║██╔██╗ ██║
██   ██║██║   ██║██╔══██║██╔══██║██║╚██╗██║
╚█████╔╝╚██████╔╝██║  ██║██║  ██║██║ ╚████║
 ╚════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝
 
*/
int main()
{
    ll n,m,mx=0;
    cin>>n>>m;
    rep2(i,m) 
    {
        ll x;
        cin>>x;
        mx+=x;
    }
    if(mx>n) cout<<"-1"<<endl;
    else cout<<n-mx<<endl;
    return 0;
}