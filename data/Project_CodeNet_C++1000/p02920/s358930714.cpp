#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    int M = 1 << N;
    
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<bool> use(M, false);
    use[0] = true;
    
    bool check = true;
    for (int K = 0; K < N; K++) {
        vector<bool> par = use;
        int u = 1;
        int p = 0;
        int cnt = 0;
        while (cnt < (1 << K)) {
            while (!par[p])p++;
            while (use[u] || A[u] >= A[p]) {
                u++;
                if (u == M) {
                    check = false;
                    break;
                }
            }
            if (!check) break;
            use[u] = true;
            p++;
            cnt++;
        }
        if (!check) break;
    }
    cout << (check ? "Yes" : "No") << endl;
    return 0;
}
