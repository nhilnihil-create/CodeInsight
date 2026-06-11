#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

ll N, M, Q;
vector<ll> a, b, c, d;

ll score(const vector<ll> A){
    ll res = 0;
    rep(j, Q) if (A[b[j]] - A[a[j]] == c[j]) res += d[j];
    return res;
}

ll dfs(vector<ll> &A){
    if(A.size() == N){
        return score(A);
    }

    ll p = (A.empty() ? 1 : A.back()), res = 0;
    for(ll i = p; i <= M; i++) {
        A.PB(i);
        res = max(dfs(A), res);
        A.pop_back();
    }
    return res;
}

int main(){
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    rep(i, Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }
    vector <ll> A;
    cout << dfs(A) << endl;
    return 0;
}