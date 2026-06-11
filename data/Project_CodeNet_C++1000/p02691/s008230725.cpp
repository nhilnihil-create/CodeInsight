#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1234567;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// o o o o o o o o o o o o
// ↑           ↑
// i - - - - - j
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    map<int,int>Mp;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        Mp[A[i]+i+1]++;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans+=Mp[i+1-A[i]];
    }
    cout << ans << endl;
}