#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int main() {
    int N; cin >> N;
    int P[N], Q[N];
    int arr[N];
    rep(i, N) {
        cin >> P[i];
        arr[i] = i + 1;
    }
    rep(i, N) cin >> Q[i];
    int p;
    int q;
    int num = 1;
    do {
        bool p_flag = true;
        rep(i, N) {
            if (P[i] != arr[i]) p_flag = false;
        }
        if (p_flag) p = num;
        bool q_flag = true;
        rep(i, N) {
            if (Q[i] != arr[i]) q_flag = false;
        }
        if (q_flag) q = num;
        num++;

    } while (next_permutation(arr, arr + N));
    printf("%d\n", abs(p - q));


    return 0;
}
