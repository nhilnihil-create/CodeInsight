#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    ll K; cin >> K;
    vector<ll> A(N), F(N);
    ll atotal = 0;
    rep(i, N){
        cin >> A[i];
        atotal += A[i];
    }
    rep(i, N){
        cin >> F[i];
    }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());

    if(atotal <= K){
        cout << 0 << endl;
    } else {
        ll left = 0;
        ll right = 1e12;
        while(right - left > 1){
            ll mid = (left+right) / 2;
            ll cnt = 0;
            rep(i, N){
                if(A[i] * F[i] > mid){
                    ll m = mid / F[i];
                    cnt += A[i] - m;
                }
            }
            if(cnt <= K){
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << right << endl;
    }

    return 0;
}