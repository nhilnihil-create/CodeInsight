#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    rep(a,10) {
        rep(b,10) {
            rep(c,10) {
                char d1 = '0' + a;
                char d2 = '0' + b;
                char d3 = '0' + c;
                bool t1,t2,t3;
                t1 = t2 = t3 = false;
                rep(i,N) {
                    if (d1==S[i] && t1==false) {
                        t1 = true;
                    }
                    else if (d2==S[i] && t2==false && t1==true) {
                        t2 = true;
                    }
                    else if (d3==S[i] && t3==false && t1==true && t2==true) {
                        t3 = true;
                    }
                }
                if (t3) ans++;
                //if (t3) cout << d1 << d2 << d3 << endl;
            }
        }
    }
    cout << ans << endl;
}
