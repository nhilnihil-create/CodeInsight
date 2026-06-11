#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;

int main() {
    int H, W, K; cin >> H >> W >> K;
    vvi c(W, vi(H));
    int ans = 0;

    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char tmp; cin >> tmp;
            if (tmp == '.') c.at(j).at(i) =0;
            else c.at(j).at(i) =1;
        }
    }
    
    for (int bit = 0; bit < (1 << W); bit++) {
        vi tmp(H, 0);
        for (int i = 0; i < W; i++) {
            if (bit & (1 << i)) {
                for (int j = 0; j < H; j++){
                    tmp.at(j) += c.at(i).at(j);
                }   
            }
        }

        for (int bit2 = 0; bit2 < (1 << H); bit2++) {
            int tmp2 = 0;
            for (int j = 0; j < H; j++) {
                if (bit2 & (1<<j)) {
                    tmp2 += tmp.at(j);
                }
            }
            if (tmp2 == K)  ans++;
            
        }
    }
    cout << ans;
}