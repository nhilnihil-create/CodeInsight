#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),F(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> F[i];
    // 大きいものと小さいものがペアになるように掛け算をする
    sort(A.begin(),A.end());
    sort(F.rbegin(),F.rend());
    ll ok = 1000000000100;
    ll ng = -1;
    ll AAA = 0;
    while(ok-ng>1){
        AAA++;
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        bool f = true;
        rep(i,N){
            if(A[i]*F[i]>mid){
                cnt+=(A[i]-mid/F[i]);
                if(cnt>K){
                    ng = mid;
                    f = false;
                    break;
                }
            }
        }
        if(f) ok = mid;
    }
    cout << ok << endl;
    return 0;
}