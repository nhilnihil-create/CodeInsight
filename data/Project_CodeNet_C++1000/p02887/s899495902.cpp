#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    rep(i,n-1) {
        if(s[i]==s[i+1]) --ans;
    }
    cout << ans << endl;

    return 0;
}
