//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef long long              ll;
typedef long double            ld;
typedef pair<int, int>         pi;
typedef vector<int>            vi;
typedef vector<pair<int, int>> vpi;

#define pb       push_back
#define all(x)   begin(x), end(x)
#define sz(x)    (int)(x).size()
#define ff       first
#define ss       second
#define mp       make_pair
#define lb       lower_bound
#define ub       upper_bound
#define tcase()  int t; cin >> t; while(t--)

const int MOD = 1e9 + 7; // 998244353;
const int MX  = 2e5 + 5;
const ll  INF = 1e18;
const ld  PI  = acos((ld) -1);

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void primeFactors(ll n)
{
    if(n == 1){
        cout << 0;
        return;
    }

    ll cnta = 0, cntb = 0, Ans = 0;

    while (n % 2 == 0)
    {
        n = n / 2LL;
        cnta++;
    }
    if(cnta == 1) Ans++;
    else if(cnta) Ans += (-1LL + sqrt(1LL + 8LL * cnta)) / 2LL;

    for (ll i = 3; i * i <= n; i = i + 2)
    {
        cntb = 0;
        while (n % i == 0)
        {
            n = n / i;
            cntb++;
        }

        if(cntb == 1) Ans++;
        else if(cntb) Ans += (-1LL + sqrt(1LL + 8LL * cntb)) / 2LL;
    }

    if(n > 2) Ans++;

    cout << Ans;
}

int main(){

    setIO();

    ll n;
    cin >> n;

    primeFactors(n);
}
