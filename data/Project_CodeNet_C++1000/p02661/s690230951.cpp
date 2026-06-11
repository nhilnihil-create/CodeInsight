#include<bits/stdc++.h> 
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int i = 0; i < N; i++)

int main(){
    int N;
    cin >> N;
    vector<i64> A(N);
    vector<i64> B(N);

    rep(i, N) cin >> A[i] >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    auto median = [](const vector<i64> v) -> i64 {
        const int L = v.size();
        if(v.size() % 2) return v[L/2];
        return (v[L/2-1] + v[L/2]);
    };

    if(N%2) cout << max<i64>(median(B)-median(A) + 1, 1) << endl;
    else cout << max<i64>(median(B)-median(A) + 1, 1) << endl;
}
