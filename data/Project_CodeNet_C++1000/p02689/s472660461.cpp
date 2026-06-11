#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N), A(M), B(M);
    for(int i=0; i<N; i++) cin >> H[i];
    for(int i=0; i<M; i++) cin >> A[i] >> B[i];
    set<int> st;
    for(int i=1; i<=N; i++) st.insert(i);


    for(int i=0; i<M; i++) {
        int na = H[A[i]-1];
        int nb = H[B[i]-1];
        if(na < nb) st.erase(A[i]);
        if(na > nb) st.erase(B[i]);
        if(na == nb) {
            st.erase(A[i]);
            st.erase(B[i]);
        }
    }
    cout << st.size() << endl;
}