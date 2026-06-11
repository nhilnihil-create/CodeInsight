#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N,A,B,C,D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    for(int i = A-1; i < C-1; i++) {
        if(S[i] == '#' && S[i+1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = B-1; i < D-1; i++) {
        if(S[i] == '#' && S[i+1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    if((A < B && C < D) || (B < A && C < D)) {
        cout << "Yes" << endl;
    }
    else {
        for(int i = max(A,B)-2; i < min(C,D)-1; i++) {
            if(S[i] == '.' && S[i+1] == '.' && S[i+2] == '.') {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
}
