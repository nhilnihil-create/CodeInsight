#include <bits/stdc++.h>

#define N_MAX 200005

using namespace std;

int N, M;
bool taken[N_MAX];
set <int> dist;
pair <int, int> ans[N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    int half = N / 2;
    int L = 0;
    for(int i = 1, j = half; i < j; i++, j--) {
        ans[L++] = make_pair(i, j);
    }

    for(int i = half + 1, j = N - (N % 2 == 0); i < j; i++, j--) {
        ans[L++] = make_pair(i, j);
    }


    for(int i = 0; i < M; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}
