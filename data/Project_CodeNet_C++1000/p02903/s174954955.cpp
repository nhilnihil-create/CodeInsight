#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll H, W, A, B, flag=0;

signed main(){
    cin >> H >> W >> A >> B;
    for(int i=0;i<H;i++) {
        if(i==B) flag=1;
        for(int j=0;j<W;j++) {
            if(!flag) {
                if(j<A) cout << "1";
                else cout << "0";
            }            
            else {
                if(j<A) cout << "0";
                else cout << "1";
            }
        }
        cout << endl;
    }
    return 0;
}