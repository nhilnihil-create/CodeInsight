#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>d(N);
    for(int i = 0; i < N; i++) {
        cin >> d[i];
    }
    sort(d.begin(),d.end());
    cout << d[N/2]-d[N/2-1] << endl;
}
