#include <bits/stdc++.h>
#define MEM 100006
#define sanic ios_base::sync_with_stdio(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll MOD = 1e9+7;
ll n,m;
string s;
int main()
{
    sanic; cin.tie(0);
    cin >> n;
    while(n>0){
        n--;
        s += (char)(97+n%26);
        n /= 26;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
