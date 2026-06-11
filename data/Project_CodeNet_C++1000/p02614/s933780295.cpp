#include <bits/stdc++.h>
using namespace std;
int main(){
    int H,W,K,ans=0;
    cin >> H >> W >> K;
    vector<string> C(H);
    for(int i=0;i<H;i++) cin >> C.at(i);

    for(int i=0;i<(1<<H);i++){
        for(int j=0;j<(1<<W);j++){
            int cnt = 0;

            for(int m=0;m<H;m++){
                for(int n=0;n<W;n++){
                    if(i>>m&1) continue;
                    if(j>>n&1) continue;
                    if(C.at(m).at(n)=='#') cnt++;
                }
            }
            if(cnt==K) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}