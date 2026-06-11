#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long, long long> pll;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main(){
    ll N, K; cin >> N >> K;
    vector<ll> A(N), F(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> F[i];

    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());


    ll lb = -1, ub = 1e13;
    while(ub - lb > 1){
        ll m = (lb + ub) / 2;
        ll cnt = 0;
        bool flag = 1;
        rep(i, 0, N){
            if(m < A[i] * F[i]){
                cnt += (A[i] * F[i] - m + F[i] - 1) / F[i];
            }
            if(cnt > K){
                flag = 0;
                break;
            }
        }
        if(flag) ub = m;
        else lb = m;
    }
    cout << ub << endl;
}
