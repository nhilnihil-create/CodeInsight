#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    string s;
    cin >> s;
    rep(i,s.size()) {
        if(i%2==0 && s[i]=='L') {
            cout << "No" << endl;
            return 0;
        } else if(i%2 && s[i]=='R') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
