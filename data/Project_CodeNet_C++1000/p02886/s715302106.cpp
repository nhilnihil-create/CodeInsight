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
map<string,int> p;
// ll lcm(ll a ,ll b)
// {
//     return (a*b)/__gcd(a,b);
// }
int main()
{
    FastRead;
    ll n,mx=0;
    cin>>n;
    ll a[n];
    rep2(i,n)
    {
        cin>>a[i];
    }
    bool p[n][n]={0};
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i==j) continue;
            else
            {
                if(!p[i][j])
                {
                    mx+=a[i]*a[j];
                    p[i][j]=1;
                    p[j][i]=1;
                }
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}