#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    rep(i,n) {
        cout << s[i] << t[i];
    }
    cout << endl;

    return 0;
}
