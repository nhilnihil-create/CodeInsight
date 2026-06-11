#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main()  {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i = 0; i < 1000; i++) {
        string T = "";
        T+=to_string(i/100);
        T+=to_string((i%100-i%10)/10);
        T+=to_string(i%10);
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(S[j] == T[cnt]) {
                cnt++;
            }
            if(cnt == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}