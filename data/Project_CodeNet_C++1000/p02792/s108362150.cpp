#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


P makepair(int x){
    int first, last;
    last = x % 10;
    while (x != 0){
        first = x;
        x /= 10;
    }
    return P(first, last);
}

int main(){
    int N; cin >> N;
    map<P, int> counter;
    for (int i = 1; i <= N; i++){
        P p = makepair(i);
        counter[p]++;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++){
        P p = makepair(i);
        P r = P(p.second, p.first);
        ans += counter[r];
    }

    cout << ans << endl;
}
