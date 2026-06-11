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
    int K;
    cin >> S >> K;
    int cnt1 = 0,sum1 = 0;
    for(int i = 0; i < (int)S.size()-1; i++) {
        if(S[i] == S[i+1]) {
            sum1++;
        }
        else {
            cnt1+=(sum1+1)/2;
            sum1 = 0;
        }
    }
    bool ok = false;
    if(sum1 == S.size()-1) ok = true;
    cnt1+=(sum1+1)/2;
    int cnt2 = 0,sum2 = 0;
    string T = S;
    T+=S;
    for(int i = 0; i < (int)T.size()-1; i++) {
        if(T[i] == T[i+1]) {
            sum2++;
        }
        else {
            cnt2+=(sum2+1)/2;
            sum2 = 0;
        }
    }
    cnt2+=(sum2+1)/2;
    if(ok) {
        cout << ((int)S.size()*K)/2 << endl;
        return 0;
    }
    cout << cnt1+(K-1)*(cnt2-cnt1) << endl;
}
