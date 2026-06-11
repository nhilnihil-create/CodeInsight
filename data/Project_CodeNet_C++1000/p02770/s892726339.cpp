#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K,Q;
    cin >> K >> Q;
    vec<ll> D(K);
    for(int i=0;i<K;i++) cin >> D[i];

    auto solve = [&](ll N,ll X,ll M){
        vec<ll> A(K);
        for(int i=0;i<K;i++) A[i] = D[i]%M;
        ll res = 0;
        for(int i=0;i<K;i++) if(A[i]==0){
            if(N-i-2>=0) res += (N-i-2)/K+1;
        }
        res -= X/M;
        ll val = X;
        for(int i=0;i<K;i++){
            if(N-i-2>=0) val += ((N-i-2)/K+1)*A[i];
        }
        res += val/M;
        cout << N-1-res << "\n";
    };
    
    while(Q--){
        ll n,x,m;
        cin >> n >> x >> m;
        solve(n,x,m);
    }
}