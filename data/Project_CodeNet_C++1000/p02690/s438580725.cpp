#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int X;
    cin >> X;
    for(int i = -1000; i <= 1000; i++) {
        for(int j = -1000; j <= 1000; j++) {
            if(pow(i,5)-pow(j,5) == X) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}
