#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll all_sum = 0;
    rep(i,N) all_sum += A[i];
    vector<ll> B(N);
    B[0] = A[0];
    rep(i,N - 1) B[i + 1] = B[i] + A[i + 1];
    ll min_ans = 1000000000000000000;
    rep(i,N){
        ll ans_sub = abs(2 * B[i] - all_sum);
        min_ans = min(min_ans, ans_sub);
    }
    cout << min_ans << endl;
}
