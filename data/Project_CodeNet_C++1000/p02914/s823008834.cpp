#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vec<ll> A(N);
    ll X = 0;
    for(auto& x:A){
        cin >> x;
        X ^= x;
    }
    ll ans = 0;
    int M = 60;
    for(int i=0;i<M;i++) if(X>>i&1){
        ans += 1LL<<i;
        for(int j=0;j<N;j++) if(A[j]>>i&1) A[j] ^= 1LL<<i;
    }

    int r = 0;
    for(int i=M-1;i>=0;i--){
        bool ok = false;
        for(int j=r;j<N;j++) if(A[j]>>i&1){
            swap(A[j],A[r]);
            ok = true;
            break;
        }
        if(ok){
            for(int j=0;j<N;j++) if(j!=r && (A[j]>>i&1)) A[j] ^= A[r];
            r++;
        }
    }
    ans += 2*accumulate(A.begin(),A.end(),0LL,[](ll a,ll b){return a^b;});
    cout << ans << "\n";
}