#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main() {
    int N;
    cin >> N;
    vector<int>ans(N);
    for(int i = 1; i < N; i++) {
        int A;
        cin >> A;
        A--;
        ans[A]++;
    }
    for(int i = 0; i < N;  i++) {
        cout << ans[i] << endl;
    }
}
