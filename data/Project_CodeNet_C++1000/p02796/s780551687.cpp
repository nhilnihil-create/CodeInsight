#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int N, ans;
    cin >> N;
    vector<l_l> arms(N, {0,0});

    rep(i, N){
        ll X, L;
        cin >> X >> L;
        arms[i] = make_pair(X + L, X - L);
    }
    sort(arms.begin(), arms.end());

    ll lastEdge = arms[0].first;
    ans = 1;
    for(int i = 1; i < N; i++){
        if(arms[i].second >= lastEdge){
            lastEdge = arms[i].first;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
