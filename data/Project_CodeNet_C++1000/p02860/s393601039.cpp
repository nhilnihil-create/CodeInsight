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
    if(n%2) {
        puts("No");
        return 0;
    }
    rep(i,n/2) {
        if(s[i] != s[i+n/2]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");

    return 0;
}
