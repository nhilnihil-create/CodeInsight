#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;

    string left = "", right = "";
    bool rev = false;
    int t, f;
    char c;
    for (int i = 0; i < q; ++i) {
        cin >> t;
        if (t == 1){
            rev = !rev;
        } else{
            cin >> f >> c;
            if (f == 1){
                if (rev) right += c;
                else left += c;
            } else{
                if (rev) left += c;
                else right += c;
            }
        }
    }
    if (rev){
        reverse(all(right));
        reverse(all(s));
        cout << right + s + left << endl;
    } else{
        reverse(all(left));
        cout << left + s + right << endl;
    }
}