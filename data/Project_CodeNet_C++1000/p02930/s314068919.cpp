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

#define MN 505
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n-1){
        FOR(j, i+1, n-1){
            int ree = i ^ j;
            cout << __builtin_ctz(ree)+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
