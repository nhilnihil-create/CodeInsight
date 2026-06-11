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
    string T; cin >> T;
    int ans = 0;
    rep(i, T.size()) {
        if(T[i] == '?') T[i] = 'D';
    }
    rep(i, T.size()) {
        if(T[i] == 'D') ++ans;
        if(i != T.size() - 1) {
            if(T[i] == 'P' && T[i + 1] == 'D') ++ans;
        }
    }
    cout << T << endl;
}
