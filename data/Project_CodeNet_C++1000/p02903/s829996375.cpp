#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
typedef long long ll;
//ll mod = 1e9+7;
ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    rep(i, h) {
        rep(j, w) {
            if ( i < b && j < a ) {
                cout << 0;
            }
            else if ( i < b && j >= a ) {
                cout << 1;
            }
            else if ( i >= b && j < a ) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}
