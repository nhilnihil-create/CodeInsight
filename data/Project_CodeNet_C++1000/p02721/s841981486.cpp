#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K,C;
    string S;
    cin >> N >> K >> C >> S;
    vector<int>cnt;
    vector<int>res;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            cnt.push_back(i);
            if(res.size() == 0) {
                res.push_back(i);
            }
            else if(res.back()+C < i) {
                res.push_back(i);
            }
        }
    }
    if(res.size() > K) {
        return 0;
    }
    vector<int>res2;
    for(int i = N-1; i >= 0; i--) {
        if(S[i] == 'o') {
            if(res2.size() == 0) {
                res2.push_back(i);
            }
            else if(res2.back()-C > i) {
                res2.push_back(i);
            }
        }
    }
    for(int i = 0; i < K; i++) {
        if(i+1 != K) {
            if(cnt[lower_bound(cnt.begin(),cnt.end(),res[i]+1)-cnt.begin()]+C < res2[K-i-2]) {
                continue;
            }
            cout << res[i]+1 << endl;
        }
        else if(res[i] == res2[K-i-1]){
            cout << res[i]+1 << endl;
        }
    }
}
