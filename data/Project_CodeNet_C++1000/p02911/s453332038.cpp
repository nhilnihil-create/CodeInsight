#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll N, K, Q;
vector<ll> A;

int main() {
    cin >>N >> K >> Q;
    A.resize(Q);
    for (int i = 0; i < Q; i++) {cin >> A[i]; A[i]--;}
    vector<ll> P(N);
    for (int i = 0; i < Q; i++) {
      P[A[i]]++;
    }
    for (int i = 0; i < N; i++){
        if(K-abs(P[i]-Q)>0) cout << "Yes" << endl;
        else cout << "No" << endl;
    } return 0;
}