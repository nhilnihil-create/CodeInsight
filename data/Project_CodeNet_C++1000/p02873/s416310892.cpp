#include <bits/stdc++.h>
#define rep(i, z, n) for(int64_t i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979
//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
//const int MODINF = 1000000007;
//const int64_t INF = 998244353;
using namespace std;
int main(){
    string S;
    cin >> S;
    int64_t count_d = 0, count_u = 0, ans = 0;
    int64_t cor = 0;
    bool way = false;
    rep(i, 0, S.size()){
        char x = S.at(i);
        if(x == '<'){
            way = true;
            count_u++;
        }
        if(x == '>'){
            if(way){
                ans += max(cor, count_d);
                ans += ((count_u) * (count_u - 1) + (count_d) * (count_d - 1)) / 2;
                cor = count_u;
                count_u = 0;
                count_d = 0;
                way = false;
                //cout << ans << endl;
            }
            count_d++;
        }
    }
    ans += max(cor, count_d);
    ans += ((count_u) * (count_u + 1) + (count_d) * (count_d - 1)) / 2;
    cout << ans << endl;
}