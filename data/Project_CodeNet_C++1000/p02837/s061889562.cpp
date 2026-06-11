#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>



using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int G[15][15];

int main(){
    int n;
    cin >> n;
    rep(i,n)rep(j,n) G[i][j] = -1;
    rep(i,n){
        int m;
        cin >> m;
        rep(j,m){
            int a,x;
            cin >> a >> x;
            a--;
            G[i][a] = x;
        }
    }
    int ans=0;
    rep(i,1<<n){
        vector<int> d(n);
        rep(j,n){
            // iを二進数であらわして、j桁目が1であるかどうかを判定、１ならjは正直者としてbit全探索の準備
            if((i>>j) & 1){ 
                d[j] = 1;
            }
        }
        bool ok = true;
        rep(j,n){
            rep(k,n){
                //cout << G[j][k] << " " << d[k] << endl;
                if(d[j] == 1){
                    //cout << G[j][k] << " " << d[k] << endl;
                    if(G[j][k] == -1) continue;
                    if(G[j][k] != d[k]) ok = false;  
                }
            }
        }

        if(ok){
            //cout << "helloL " << endl;
            int anscandi=0;
            rep(j,n){
                if((i>>j) & 1) anscandi++; 
            }
            ans = max(ans, anscandi);
        }
    }
    cout << ans << endl;
    return 0;
}