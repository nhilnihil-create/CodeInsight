#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M, K, conv;
    cin >> N >> M >> K;
    
    vector<long> A(N + 1), B(M + 1);
    A.at(0) = 0;
    B.at(0) = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> conv;
        A.at(i) = conv + A.at(i - 1);
    }
    for (int i = 1; i < M + 1; i++) {
        cin >> conv;
        B.at(i) = conv + B.at(i - 1);
    }
    
    
    
    int ans = 0, m = M;
    for (int i = 0; i < N + 1; i++) {
        if (A.at(i) > K) {
            break;
        }
        while (K < A.at(i) + B.at(m)) {
            m--;
        }

        ans = max(ans, i + m);
    }
    
    cout << ans << endl;
    
}
