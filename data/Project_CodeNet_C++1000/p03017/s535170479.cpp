#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;
    string s;
    cin >> s;
    if(c < d){
        for(int i = a; i < d; i++){
            if(s[i] == '#' && s[i+1] == '#'){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else{
        for(int i = a; i < d; i++){
            if(s[i] == '#' && s[i+1] == '#'){
                cout << "No" << endl;
                return 0;
            }
        }
        for(int i = b-1; i < d; i++){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    
}