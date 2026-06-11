#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define int long long
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    int M = N-1;
    int ans = 0;
    for(int i = 2; i*i <= M; i++) {
        if(M%i == 0) {
            ans++;
            if(i*i != M) {
                ans++;
            }
        }
    }
    for(int i = 2; i*i <= N; i++) {
        if (N%i == 0) {
            int X = N;
            int Y = N;
            while (X%i == 0) {
                X/=i;
            }
            if (X%i == 1) {
                ans++;
            }
            int Z = N/i;
            if (Z != i) {
                while (Y%Z == 0) {
                    Y/=Z;
                }
                if (Y%Z == 1) {
                    ans++;
                }
            }
        }
    }
    if(N == 2) {
        cout << 1 << endl;
        return 0;
    }
    cout << ans+2 << endl;
}
