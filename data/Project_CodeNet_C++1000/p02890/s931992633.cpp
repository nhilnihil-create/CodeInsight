#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int N;
vector<int> a;
vector<int> sum;

void input() {
    cin >> N;
    a = vector<int>(N);
    rep(i, N) {
        int x;
        cin >> x;
        a[x-1]++;
    }
}

inline bool judge(int& ans, int& k) {
    if (ans == 0) return true;
    int index = upper_bound(a.begin(), a.end(), ans) - a.begin();
    int x = sum[index-1] + ans * (N - index);
    if (x >= ans * k) return true;
    return false;
}

int main() {
    input();
    sort(a.begin(), a.end());
    sum = vector<int>(N);
    sum[0] = a[0];
    for (int i = 1; i < N; i++) sum[i] = sum[i-1] + a[i];
    int ans = N;
    for (int k = 1; k <= N; k++) {
        while (!judge(ans, k)) ans--;
        cout << ans << endl;
    }
}
