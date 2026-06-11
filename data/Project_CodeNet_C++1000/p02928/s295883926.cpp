#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (ll i=(a); i >= b; i--)

#define MN 100005
int n;
ll k;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    F0R(i, n){
        cin >> a[i];
    }
    ll res = 0;
    F0R(i, n){
        FOR(j, i+1, n-1){
            if(a[i] > a[j]){
                res += k*(k+1)/2;
            } else if(a[i] < a[j]){
                res += k*(k-1)/2;
            }
            res %= MOD;
        }
    }
    cout << res << "\n";

    return 0;
}
