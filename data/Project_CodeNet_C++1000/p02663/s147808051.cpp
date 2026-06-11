#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 70
int h1, m1, h2, m2, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int a = h1*60+m1, b=h2*60+m2;
    cout << (b-a)-k << "\n";

    return 0;
}
