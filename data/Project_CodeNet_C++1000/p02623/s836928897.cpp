#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define MOD 1000000007
#define enld endl
typedef long long ll;
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll N,M,K; cin >> N >> M >> K;
    vector<ll> A(N+1,0),B(M+1,0),a(N),b(M);
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<M;i++) cin >> b[i];
    for(int i=0;i<N;i++) A[i+1] = A[i] + a[i];
    for(int i=0;i<M;i++) B[i+1] = B[i] + b[i];

    ll ans = 0;
    for(ll i=0;i<=N;i++){
        if(K < A[i]) break;
        ll cnt = upper_bound(B.begin(), B.end(), K - A[i]) - B.begin();
        if(A[i] + B[cnt-1] <= K){
            ans = (ll)(max(ans, i+cnt-1));
        }
    }
    cout << ans << endl;
    return 0;
}