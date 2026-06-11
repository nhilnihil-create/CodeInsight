#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--, b--, c--, d--;
    string s; cin >> s;

    bool ok = true;
    for(int i = a; i <= c; i++){
        if(s[i] == '#' && s[i + 1] == '#'){
            ok = false;
            break;
        }
    }
    for(int i = b; i <= d; i++){
        if(s[i] == '#' && s[i + 1] == '#'){
            ok = false;
            break;
        }
    }
    if(!ok) {
        cout << "No" << endl;
        return 0;
    }

    if(d < c){
        bool flag = false;
        for(int i = b; i <= d; i++){
            if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
