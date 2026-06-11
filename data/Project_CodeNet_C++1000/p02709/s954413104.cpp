/*
 ID: swagchicken1
 PROG:
 LANG: C++11
 */

#include <iostream>
#include <tuple>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <climits>
#include <chrono>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector <int> > vvi;
typedef pair<int, int> pii;
typedef pair < pair < int, int >, int > piii;
typedef pair < pair <int, int > , pair <int, int> > piiii;

#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define RFOR(i,a,b) for(int i = a-1; i >= b; i --)

//#define endl '\n';

#define mp make_pair
#define pb push_back
#define f first
#define s second

const int MOD = 1000000007;

long double PI = 4*atan(1);
long double eps = 1e-12;


ll dp[2010][2010] = {};
int main() {
    //auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);cin.tie(0);
    //ofstream cout("output.txt");
    //ifstream cin("input.txt");
    ll n; cin >> n;
    pair<ll, int> a[2010] = {};
    FOR(i,0,n) {
        cin >> a[i].f;
        a[i].s = i;
    }
    sort(a,a+n, greater<pair<ll, int>>());
    dp[0][0] = 0;
    FOR(i,1,n+1) {
        FOR(j,0, i+1) {
            int x = j;
            int y = i - j;
            if(x > 0) {
                dp[x][y] = max(dp[x][y], dp[x-1][y] + a[i-1].f*(abs(a[i-1].s - x + 1)));
            }
            if(y > 0) {
                dp[x][y] = max(dp[x][y], dp[x][y-1] + a[i-1].f*(abs(n - y - a[i-1].s)));
            }
        }
    }
    ll ans = 0;
    FOR(i,1,n+1) {
        ans = max(ans, dp[n - i][i]);
    }
    cout << ans << endl;
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //cout << duration.count() << endl;
    //cin.close();
    //cout.close();
}
