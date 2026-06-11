#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int H,W,A,B;
    cin >> H >> W >> A >> B;
    
    rep(h,H) {
        rep(w,W) {
            if (w+1<=A && h+1<=B) {
                cout << 1;
            }
            else if (w+1>A && h+1>B) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }
}
