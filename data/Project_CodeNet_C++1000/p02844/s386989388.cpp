#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11


int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    rep(i,1000){
        string tmp = "";
        if(i < 10) tmp += "00";
        else if(i < 100) tmp += "0";
        tmp += to_string(i);
        int id1 = 300000,id3 = -1;
        bool ok = false;
        rep(j,n){
            if(s[j] == tmp[0]){
                id1 = j;
                break;
            }
        }
        for(int j = n-1; j >= 0; j--){
            if(s[j] == tmp[2]){
                id3 = j;
                break;
            }
        }
        rep(j,n){
            if(s[j] == tmp[1] && id1 < j && j < id3){
                ok = true;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}