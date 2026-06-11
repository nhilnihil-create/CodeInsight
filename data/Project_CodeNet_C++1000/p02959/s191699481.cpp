#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> A(N+1);
    vector <long long> B(N);
    for (long long i=0; i<=N; i++) cin >> A.at(i);
    long long ans=0;
    for (long long i=0; i<N; i++) {
        long long B;
        cin >> B;
        ans += min(B, A.at(i));
        B = max((long long)0, B-A.at(i));
        if (B>0) {
            ans += min(B, A.at(i+1));
            A.at(i+1)=max((long long)0, A.at(i+1)-B);
        }
    }
    cout << ans;
}