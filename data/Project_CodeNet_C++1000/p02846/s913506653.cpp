#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    int T1,T2,A1,A2,B1,B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    int X = (A1-B1)*T1;
    int Y = (A2-B2)*T2;
    if(X < 0) {
        X*=-1;Y*=-1;
    }
    if(X == -Y) {
        cout << "infinity" << endl;
    }
    // X-Y+X-Y+X-Y
    else if(X+Y > 0) {
        cout << 0 << endl;
    }
    else {
        // 2 3 2 3 2 3 2 3 2 3 2 3
        // 2 -1 1 -2 0 -3 -1
        if(X%(abs(X+Y)) == 0) {
            cout << X/(abs(X+Y))*2 << endl;
        }
        else {
            cout << X/(abs(X+Y))*2+1 << endl;
        }
    }
}
