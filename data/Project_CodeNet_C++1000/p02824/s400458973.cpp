#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T,class U> using P = pair<T,U>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,V,P;
    cin >> N >> M >> V >> P;
    vec<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    sort(A.rbegin(),A.rend());

    auto ok = [&](int m){
        vec<ll> B = A;
        B[m] += M;
        if(B[m]<B[P-1]) return false;
        ll res = M*(V-1);
        for(int i=0;i<P-1;i++){
            res -= M;
            if(res<=0) return true;
        }
        for(int i=N-1;i>m;i--){
            res -= min(B[m]-B[i],M);
            if(res<=0) return true;
        }
        for(int i=m-1;i>=P-1;i--){
            if(B[i]>B[m]) return false;
            else{
                res -= min(B[m]-B[i],M);
                if(res<=0) return true;
            }
        }
        return res<=0;
    };

    int l = P-1,r = N;
    while(l+1<r){
        int m = (l+r)>>1;
        (ok(m)? l:r) = m;
    }
    cout << r << endl;
}