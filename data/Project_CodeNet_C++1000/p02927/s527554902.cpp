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
int m, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> d;
    int cnt = 0;
    FOR(i, 1, m){
        FOR(j, 1, d){
            int a = j/10, b = j%10;
            if(a <= 1 || b <= 1) continue;
            if(a*b==i) ++cnt;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}
