#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0), B(N + 1, 0), C(N + 1, 0), S(N + 1, 0), lS(N + 1, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        B[A[i]]++;
    }
    for(int j = 0; j <= N; j++) {
        C[B[j]]++;
    }
    for(int k = 0; k <= N; k++) {
        S[k] += C[k];
        lS[k] += k * C[k];
        if(k) {
            S[k] += S[k - 1];
            lS[k] += lS[k - 1];
        }
    }
    vector<int> X_K(N + 1), ans(N);
    X_K[0] = N;
    for(int X = 1; X <= N; X++) {
        X_K[X] = (lS[X] + X * (S[N] - S[X])) / X;
    }
    int x = N;
    for(int K = 1; K <= N; K++) {
        while(K > X_K[x]) x--;
        cout << x << endl;
    }
    return 0;
}