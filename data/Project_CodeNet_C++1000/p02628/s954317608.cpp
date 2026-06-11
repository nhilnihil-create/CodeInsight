#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N, K;
    cin >> N >> K;
    int p[N];
    rep(i, N) cin >> p[i];
    sort(p + 0, p + N);
    int ans = 0; 
    rep(i, K) ans += p[i];
    cout << ans <<endl;

    return 0;    
}