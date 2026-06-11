#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}



int main() {
    int n,ans = 0;
    string s;
    cin >> n;
    cin >> s;
    // 000 ~ 009までのチェック
    for (int i = 0; i <= 9; ++i) {
        int flg = 0,flg2 = 0;
        for (int a = 0; a < n; ++a) {
            if(s[a]-'0' == 0 && flg == 0){
                flg = 1;
                continue;
            }
            if(s[a]-'0' == 0 && flg == 1 && flg2 == 0){
                flg2 = 1;
                continue;
            }
            if(s[a]-'0' == i && flg == 1 && flg2 == 1){
                ans++;
                break;
            }
        }
    }

    // 010 ~ 099
    for (int i = 10; i <= 99; ++i) {
        int manaka = (i/10);
        int flg = 0,flg2 = 0;
        for (int a = 0; a < n; ++a) {
            if(s[a]-'0' == 0 && flg == 0){
                flg = 1;
                continue;
            }
            if(s[a]-'0' == manaka && flg == 1 && flg2 == 0){
                flg2 = 1;
                continue;
            }
            if(s[a]-'0' == (i%10) && flg == 1 && flg2 == 1){
                ans++;
                break;
            }
        }
    }

    // 100 ~ 999
    for (int i = 100; i <= 999; ++i) {
        int ue = (i/100),manaka = (i/10)%10;
        int flg = 0,flg2 = 0;
        for (int a = 0; a < n; ++a) {
            if(s[a]-'0' == ue && flg == 0){
                flg = 1;
                continue;
            }
            if(s[a]-'0' == manaka && flg == 1 && flg2 == 0){
                flg2 = 1;
                continue;
            }
            if(s[a]-'0' == (i%10) && flg == 1 && flg2 == 1){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}