#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
typedef unsigned int uint;
#define MAX_R 10
#define MAX_C 10000
int R, C;
int f[MAX_R][MAX_C];
int buf[MAX_R][MAX_C];

// fのpatに1が立っている行をひっくり返してbuf に入れる
void flip(uint pat) {
    memcpy(buf,f,sizeof(f));
    for(int i=0;i<R;i++) {
        if ((pat & (1 << i)) != 0) {
            for(int j=0;j<C;j++) {
                buf[i][j] = (buf[i][j]+1) % 2;
            }
        }
    } 

    //for(int i=0;i<R;i++) {
    //    for(int j=0;j<C;j++) {
    //        cout << buf[i][j] << " ";
    //    }
    //    cout << endl;
    //}

}

void solve() {
    int ans = 0;
    // 行についてすべてのパターンを試す
    int nums = pow(2,R);
    for(uint pat = 0; pat < nums; pat++) {
        flip(pat);
        // 列
        int cnt_b; // 黒の数
        int buf_ans = 0;
        for(int i=0;i<C;i++) {
            cnt_b = 0;
            for(int j=0;j<R;j++) {
               if(buf[j][i] == 1) cnt_b++;
            }
            if(cnt_b > R/2) {
                buf_ans += cnt_b; // ひっくり返す
            } else {
                buf_ans += R - cnt_b;
            }
        }
        ans = max(ans, buf_ans);
    }
    cout << ans << endl;
}

main() {
    while(cin>>R>>C, R!=0 && C!=0) {
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                cin>>f[i][j];
            }
        }
        solve();
    }
}