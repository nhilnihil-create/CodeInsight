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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
string s;
int a, b, c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> a >> b >> c >> d;
    cin >> s;
    --a; --b; --c; --d;

    FOR(i, a, c){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No\n";
            return 0;
        }
    }
    FOR(i, b, d){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No\n";
            return 0;
        }
    }
    if(c < d){
        cout << "Yes\n";
        return 0;
    }
    FOR(i, b, d){
        if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
