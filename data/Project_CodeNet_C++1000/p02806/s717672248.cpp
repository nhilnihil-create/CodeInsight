#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    string s[N]; int t[N];
    int sum = 0;
    rep(i, N) cin >> s[i] >> t[i], sum += t[i];
    string X; cin >> X;
    int sum_X = 0;
    rep(i, N) {
        sum_X += t[i];
        if(s[i] == X) {
            cout << sum - sum_X << endl;
            return 0;
        }
    }
}
