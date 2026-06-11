#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    int S;
    cin >> S;
    if(S == 1000000000000000000) {
        cout << 0 << " " << 0 << " " << 1000000000 << " " << 0 << " " << 0 << " " << 1000000000 << endl;
        return 0;
    }
    cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 <<" ";
    int X = S/1000000000+1;
    int Y = X*1000000000-S;
    cout << Y << " " << X << endl;
}
