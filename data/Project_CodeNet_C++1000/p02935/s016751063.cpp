#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int  N;
    cin >> N;
    vector<double>u(N);
    double cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> u[i];
    }
    sort(u.begin(),u.end());
    cnt = u[0];
    for(int i = 1; i < N; i++) {
        cnt+=u[i];
        cnt/=2;
    }
    cout << cnt << endl;
}