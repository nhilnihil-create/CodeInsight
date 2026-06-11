#include <bits/stdc++.h>
using namespace std;

int gcd_func(int a, int b){
    return b? gcd_func(b, a%b) : a;
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int h, w, k; cin >> h >> w >> k;
    char gd[7][7];
    for(int i = 0; i < h; i++){
        for(int j = 0; j<w; j++){
            cin>>gd[i][j];
        }
    }
    int ns = 0;
    for(int combx = 0; combx < (1<<h); combx++){
        for(int comby = 0; comby < (1<<w); comby++){
            int cnt = 0;
            for(int x = 0; x < h; x++){
                for(int y = 0; y < w; y++){
                    if(!(combx&(1<<x)) && !(comby&(1<<y)) && gd[x][y] == '#')
                        cnt++;
                }
            }
            if(cnt == k){
                ns++;
            }
        }
    }
    cout << ns << endl;
    return 0;
}