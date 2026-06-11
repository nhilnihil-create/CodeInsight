#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll H, W, K; cin >> H >> W >> K;
    vector<string> S(H); 
    for(int i = 0; i < H; i++) cin >> S[i];
    ll ans = 0;

    for(int i = 0; i < (1<<H); i++){
        for(int j = 0; j < (1<<W); j++){
            bitset<10> BH = i, BW = j;
            ll cnt = 0;
            for(int h = 0; h < H; h++){
                for(int w = 0; w < W; w++){
                    if(!BH[h] && !BW[w] && S[h][w] == '#') cnt++;
                }
            }
            if(cnt == K) ans++;


        }
    }
    cout << ans << endl;

}