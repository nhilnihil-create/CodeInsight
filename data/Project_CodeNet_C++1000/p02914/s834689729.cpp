#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    cin >> N;
    vector<i64> A(N);
    i64 S = 0;
    for(auto &x : A) {
        cin >> x;
        S ^= x;
    }
    const int MAX_BIT = 60;
    int j = 0;
    for(int b = MAX_BIT; b >= 0; b--) {
        i64 p = 1ll << b;
        bool reduction = false;
        if (S & p || j < 0) continue;
        for(int i = j; i < N; i++) {
            if(A[i] & p) {
                swap(A[i], A[j]);
                reduction = true;
                break;
            }
        }
        if (!reduction) continue;
        for(int i = 0; i < N; i++) {
            if(i != j && (A[i] & p)) {
                A[i] ^= A[j];
            }
        }
        j++;
    }
    i64 X = 0;
    for(int i = 0; i < N; i++) {
        X ^= A[i];
    }
    i64 ans = X + (S ^ X);
    cout << ans << endl;
    return 0;
}