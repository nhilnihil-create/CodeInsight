#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int H,W;
    cin >> H >> W;
    while(H){
        int minh, minw, mind = INF;
        rep(i,1,151)rep(j,i+1,151){
            int d = i * i + j * j;
            if(d > H * H + W * W || (d == H * H + W * W) && (H < i)){
                if(d < mind || (d == mind && i < minh)){
                    mind = d;
                    minh = i;
                    minw = j;
                }
            }
        }
        cout << minh << " " << minw << endl;
        cin >> H >> W;
    }
}
