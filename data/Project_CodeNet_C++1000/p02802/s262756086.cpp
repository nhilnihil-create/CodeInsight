#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    int X = 0;
    int Y = 0;
    vector<bool>ok(N);
    vector<int>cnt(N);
    for(int i = 0; i < M; i++) {
        int p;
        string S;
        cin >> p >> S;
        if(!ok[p-1]) {
            if(S == "AC") {
                X++;
                ok[p-1] = true;
            }
            else {
                cnt[p-1]++;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(ok[i]) {
            Y+=cnt[i];
        }
    }
    cout << X << " " << Y << endl;
}
