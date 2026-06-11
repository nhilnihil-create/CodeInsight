#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int H,W;
    cin >> H >> W;
    vector<string>S(H);
    for(int i = 0; i < H; i++) {
        cin >> S[i];
    }
    vector<vector<int>>cnt(H,vector<int>(W));
    for(int i = 0; i < H; i++) {
        int sum = 0;
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.')sum++;
            else sum = 0;
            cnt[i][j] += sum;
        }
    }
    for(int i = 0; i < H; i++) {
        int sum = 0;
        for(int j = W-1; j >= 0; j--) {
            if(S[i][j] == '.')sum++;
            else sum = 0;
            cnt[i][j] += sum;
        }
    }
    for(int i = 0; i < W; i++) {
        int sum = 0;
        for(int j = 0; j < H; j++) {
            if(S[j][i] == '.')sum++;
            else sum = 0;
            cnt[j][i] += sum;
        }
    }
    for(int i = 0; i < W; i++) {
        int sum = 0;
        for(int j = H-1; j >= 0; j--) {
            if(S[j][i] == '.')sum++;
            else sum = 0;
            cnt[j][i] += sum;
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans = max(ans,cnt[i][j]);
        }
    }
    cout << ans-3 << endl;
}
