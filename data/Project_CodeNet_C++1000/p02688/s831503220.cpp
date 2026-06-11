#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> d(K);
    int a;
    vector<int> A;
    for (int i=0; i<K; i++) {
        cin >> d[i];
        for (int j=0; j<d[i]; j++) {
            cin >> a;
            A.push_back(a);
        }
    }
    int NA = A.size();
    vector<int> sunuke(N);
    for (int i=0; i<NA; i++) {
        if (sunuke[A[i]-1] == 0) {
            sunuke[A[i]-1] = 1;
        }
    }
    int ans = 0;
    for (int i=0; i<N; i++) {
        ans += sunuke[i];
    }
    cout << N-ans << endl;
}