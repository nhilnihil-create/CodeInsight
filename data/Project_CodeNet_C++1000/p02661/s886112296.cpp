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
    vector<ll> B(N);
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    ll ans;
    sort(all(A));
    sort(all(B));
    if (N % 2 == 0){
        ll min_ans = A[N / 2] + A[N / 2 - 1];
        ll max_ans = B[N / 2] + B[N / 2 - 1];
        ans = max_ans - min_ans + 1;
    }
    else{
        ll min_ans = A[N / 2];
        ll max_ans = B[N / 2];
        ans = max_ans - min_ans + 1;
    }
    cout << ans << endl;
}