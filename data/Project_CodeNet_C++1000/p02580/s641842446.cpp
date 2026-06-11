#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int H,W,M;
    cin >> H >> W >> M;
    vector<vector<int>> Ah(H,vector<int> (2));
    vector<vector<int>> Aw(W,vector<int> (2));
    
    rep(i,H) {
        Ah[i][1] = i;
    }
    rep(i,W) {
        Aw[i][1] = i;
    }
    set<pair<int,int>> S;
    rep(i,M) {
        int h,w;
        cin >> h >> w;
        h--,w--;
        Ah[h][0]++;
        Aw[w][0]++;
        S.insert(make_pair(h,w));
    }
    sort(Ah.begin(),Ah.end());
    sort(Aw.begin(),Aw.end());

    int h_max = Ah.back()[0];
    int w_max = Aw.back()[0];

    set<int> Sh,Sw;

    int idx = H-1;
    while(1) {
        if (Ah[idx][0] == h_max) {
            Sh.insert(Ah[idx][1]);
        }
        else {
            break;
        }
        idx--;
        if (idx<0) break;
    }
    idx = W-1;
    while(1) {
        if (Aw[idx][0] == w_max) {
            Sw.insert(Aw[idx][1]);
        }
        else break;
        idx--;
        if(idx<0) break;
    }
    int ans = h_max + w_max - 1;

    int tmp = Sh.size()*Sw.size();

    for (auto s:S) {
        int h = s.first;
        int w = s.second;
        if (Sh.count(h) && Sw.count(w)) {
            tmp--;
        }
    }
    if (tmp!=0) ans++;
    cout << ans << endl;

}
