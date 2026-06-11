#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string S;
    cin >> S;
    string T = "";
    string R = "0";
    int cnt = 0;
    for(int i = 0; i < S.size(); i++) {
        T+=S[i];
        if(T == R) {
            continue;
        }
        else {
            R = T;
            T = "";
            cnt++;
        }
    }
    cout << cnt << endl;
}