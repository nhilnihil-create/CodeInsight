#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    rep(i,(n+1)/2) {
        if(s[i] != s[n-1-i]) { ans++;}
    }
    cout << ans << endl;

    return 0;
}
