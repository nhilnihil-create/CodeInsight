#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,A,B;
    cin >> N >> A >> B;
    if(abs(A-B)%2 == 0) {
        cout << abs(A-B)/2 << endl;
    }
    else {
        cout << min((A+B-1)/2,(N*2-A-B+1)/2) << endl;
    }
}
