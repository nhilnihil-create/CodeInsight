#include <bits/stdc++.h>
#define MEM 200006
#define sanic ios_base::sync_with_stdio(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll MOD = 1e9+7;
ll n,m,sum;
ll c[MEM];
string s;
int main()
{
    sanic; cin.tie(0);
    cin >> n;
    ll sxm=0;
    for(int i=0; i<n; i++){
        cin >> c[i];
        sxm^=c[i];
    }
    for(int i=0; i<n; i++)
        cout << (sxm^c[i]) << ' ';
}
