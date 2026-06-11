#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string S;
    cin >> S;
    string T = S;
    reverse(T.begin(),T.end());
    string R = S.substr(0,S.size()/2);
    string I = S.substr(S.size()/2+1,S.size()/2);
    if(S == T) {
        for(int i = 0; i < R.size(); i++) {
            if(R[i] != R[R.size()-1-i] || I[i] != I[R.size()-1-i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
