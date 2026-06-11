#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    ll n; cin >> n;
    string s; cin >> s;
    char c1,c2,c3;
    bool flag[3];
    ll ans = 0;

    for(int i = 0; i < 1000; i ++){
        c1 = '0'+ i%10;
        c2 = '0'+ (i/10)%10;
        c3 = '0'+ (i/100);
        flag[0] = false;
        flag[1] = false;
        flag[2] = false;

        rep(j,s.length()){
            if(!flag[0]){
                if(s[j] == c1) flag[0] = true;
            }else if(!flag[1]){
                if(s[j] == c2) flag[1] = true;
            }else if(!flag[2]){
                if(s[j] == c3) flag[2] = true;
            }
            if(flag[0] && flag[1] && flag[2]){
                ans ++;
                break;
            }
        }
    }


    cout << ans;
    return 0;
}
