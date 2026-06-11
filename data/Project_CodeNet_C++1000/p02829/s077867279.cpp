#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int a,b;
    cin >> a >> b;
    int ans = 6 - a - b;
    cout << ans << endl;

    return 0;
}
