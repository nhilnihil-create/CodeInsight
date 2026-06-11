#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long

#define for(i,a,b) for (i=a; i<b; i++)
#define forb(i,a,b) for (i=a; i>b; i--)
#define all(S) S.begin(),S.end()
#define sort(S) sort(all(S))

const int inf = 1e9+7;
const ll INF = 1e18;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,k,i;
    cin >> n >> k;
    ll ans = 0;
    for (i,k,n+2)
    {
        ll a = (i-1)*i/2;
        ll b = n*(n+1)/2 - (n-i)*(n-i+1)/2;
        ans = (ans+b-a+1)%inf;
    }
    cout << ans << endl;
    return 0;
}
