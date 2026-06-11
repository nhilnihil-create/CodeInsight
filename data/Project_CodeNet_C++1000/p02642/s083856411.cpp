#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 1000001; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

vector<ll> b(MX), flag(MX);

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    set<ll> s;
    rep(i, N) {
        cin >> A[i];
        b[A[i]]++;
        s.insert(A[i]);
    }

    for (int i : s) {
        for (int j = 2; j < MX; j++) {
            if (i * j >= MX) break;
            flag[i * j] = 1;
        }
    }
    int ans = 0;
    rep(i, N) {
        if (b[A[i]] == 1 && !flag[A[i]]) ans++; 
    }
    cout << ans << endl;
    return 0;
}