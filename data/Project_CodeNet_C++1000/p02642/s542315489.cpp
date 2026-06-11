#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

//#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define loop(x,n) for(int x = 0; x < n; ++x)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100001;

string get_str() {
    string temp;
    cin >> temp;
    return temp;
}
int get_int() {
    int temp;
    cin >> temp;
    return temp;
}

void solve() {



}

int n, a[200000], b[200000], ans; 

int main() {
    
    cin >> n;
    vector<int> interest;
    loop(i, n) {
        cin >> a[i];
    }

    sort(a, a+n);

    vector<bool> dp(a[n-1]+1, true);

    loop(i, n) {
        if (!dp[a[i]]) continue;

        if (i > 0 && a[i] == a[i-1]) {
            dp[a[i]] = false;
            ans--;
            continue;
        }

        ans++;

        for(int j=a[i]*2; j <= a[n-1]; j+=a[i]) {
            dp[j] = false;
        }
    }

    cout << ans << endl;

}
