#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n, A, B, C, D;
string s;

int main() {
    cin >> n >> A >> B >> C >> D;
    cin >> s;
    A--; B--; C--; D--;
    bool flg = true;
    for(int i = max(1, A); i < max(C, D); ++i) {
        if(s[i-1] == '#' && s[i] == '#') {
            flg = false;
            break;
        }
    }

    if(!flg) {
        // 岩が2連続なのでどうやっても無理
        cout << "No" << endl;
    }else {
        if(C < D) {
            // Cの方が手前にゴールがある
            cout << "Yes" << endl;
        }else {
            // Dの方が手間にゴールがある
            bool flg2 = false;
            for(int i = B; i <= D; ++i) {
                if(s[i] == '.') {
                    if(s[i-1] == '.' && s[i+1] == '.') {
                        flg2 = true;
                        break;
                    }
                }
            }
            if(flg2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}