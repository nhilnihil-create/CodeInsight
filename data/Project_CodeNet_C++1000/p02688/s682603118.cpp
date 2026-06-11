#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    int N, K, a;
    cin >> N >> K;
    vector<int> d(K);
    vector<vector<int>> A(K);
    for (int i=0; i<K; i++) {
        cin >> d[i];
        for (int j=0; j<d[i]; j++) {
            cin >> a;
            A[i].push_back(a-1);
        }
    }

    vector<int> vec(N,0);
    for (int i=0; i<K; i++) {
        for (int j=0; j<d[i]; j++) {
            vec[A[i][j]]++;
        }
    }

    int ans = 0;
    for (int i=0; i<N; i++) {
        if (vec[i]==0) {
            ans++;
        }
    }

    cout << ans << endl;
}