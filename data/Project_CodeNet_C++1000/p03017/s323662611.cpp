#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    if (c < d){
        bool t = true;
        repp(i,d-2,a){
            if (s.at(i) == '#' && s.at(i+1) == '#'){
                t = false;
                break;
            }
        }
        if (t){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else{
        bool ta = true;
        bool tb = false;
        repp(i,d-2,b){
            if (s.at(i) == '#' && s.at(i+1) == '#'){
                ta = false;
                break;
            }
            if (s.at(i) == '.' && s.at(i+1) == '.' && s.at(i+2) == '.'){
                tb = true;
            }
        }
        if (s.at(b-2) == '.' && s.at(b) == '.') tb = true;
        if (s.at(d-2) == '.' && s.at(d) == '.') tb = true;
        if (s.at(b+1) == '.' && s.at(b) == '.') tb = true;
        if (ta && tb){
            ta = true;
            repp(i,c-2,a){
                if (s.at(i) == '#' && s.at(i+1) == '#'){
                    ta = false;
                    break;
                }
            }
            if (ta){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            cout << "No" << endl;
        }
    }
}