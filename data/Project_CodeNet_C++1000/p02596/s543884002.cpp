// Author : heyuhhh
// Created Time : 2020/08/30 19:28:57
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e6 + 5;
void run() {
    int k;
    cin >> k;
    int now = 0;
    for (int i = 1; i <= N; i++) {
        now = (now * 10 + 7) % k;
        if (now == 0) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}