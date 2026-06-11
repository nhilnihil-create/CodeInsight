#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define INV  500000004LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int h, w, a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> a >> b;

    FOR(i, 1, h){
        FOR(j, 1, w){
            if((i<=b)==(j<=a)){
                cout << "1";
            } else{
                cout << "0";
            }
        }
        cout << "\n";
    }

    return 0;
}
