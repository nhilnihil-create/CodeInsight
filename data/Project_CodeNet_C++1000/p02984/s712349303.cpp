#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum =0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
    }
    sum/=2;
    for(int i=1;i<N;i+=2){
         sum -= A[i];
    }
    vector<ll> ans(N);
    ans[0] = sum;
    for(int i=1;i<N;i++){
        ans[i] = A[i-1] - ans[i-1];
    }
    for(int i=0;i<N;i++){
        cout << ans[i]*2 <<" ";
    }
    cout << endl;

    return 0;
}