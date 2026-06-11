#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<int> A(N);
    Graph x(N), y(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        for(int j = 0; j < A[i]; j++) {
            int X, Y; cin >> X >> Y;
            X--;
            x[i].push_back(X);
            y[i].push_back(Y);
        }
    }
    int ans = 0;
    for(int b = 0; b < (1 << 15); b++) {
        if(b == (1 << N)) break;
        bitset<15> bit(b);
        bool judge = true;
        for(int u = 0; u < N; u++) {
            for(int v = 0; v < A[u]; v++) {
                if(bit.test(u)) {
                    if(bit.test(x[u][v])) {
                        if(!y[u][v]) judge = false;
                    }
                    else {
                        if(y[u][v]) judge = false;
                    }
                }                
            }
        }
        if(judge) ans = max(ans, (int)bit.count());
    }
    cout << ans << endl;
    return 0;
}