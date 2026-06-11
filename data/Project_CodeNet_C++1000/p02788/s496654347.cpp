#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N;
ll D, A;
vector<ll> X, H;

ll solve(){
    vector<int> ids(N);
    for(int i = 0; i < N; i++) ids[i] = i;
    sort(ids.begin(), ids.end(), [&](int i, int j) {return X[i] < X[j]; });
    vector<ll> nX(N), nH(N);
    for(int i = 0; i < N; i++) nX[i] = X[ids[i]], nH[i] = H[ids[i]];
    X = nX, H = nH;

    vector<ll> S(N+1, 0);
    ll res = 0;
    for(int i = 0; i < N; i++){
        if(S[i] < H[i]){
            ll need = (H[i] - S[i] - 1) / A + 1;
            ll right = X[i] + D * 2;
            int id = upper_bound(X.begin(), X.end(), right) - X.begin();

            S[i] += need * A;
            S[id] -= need * A;
            res += need;
        }
        S[i+1] += S[i];
    }
    return res;
}

int main(){
    cin >> N >> D >> A;
    X.resize(N); H.resize(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> H[i];
    cout << solve() << endl;
}