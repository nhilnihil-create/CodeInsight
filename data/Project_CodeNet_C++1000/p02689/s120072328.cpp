#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int H[N];
    for (int i = 0; i < N; i++) cin >> H[i];
    int A, B;
    bool judge[N];
    for (int i = 0; i < N; i++) judge[i] = true;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        A--; B--;
        if (H[A] > H[B]) judge[B] = false;
        else if (H[A] < H[B]) judge[A] = false;
        else {
            judge[A] = false;
            judge[B] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (judge[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}