#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main()
{
    fio;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,x,t;
    cin>>n>>x>>t;
    ll ans = 0,p = 0;
    while(n > p)
    {
        p+=x;
        ans+=t;
    } 
    cout<<ans;
    return 0;
}