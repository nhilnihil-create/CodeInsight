#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int N;
    cin >> N;
    vector<vector<int>>cnt(10,vector<int>(10));
    for(int i = 1; i <= N; i++) {
        string T = to_string(i);
        cnt[T[0]-'0'][T[T.size()-1]-'0']++;
    }
    int ans = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            ans+=cnt[i][j]*cnt[j][i];
        }
    }
    cout << ans << endl;
}