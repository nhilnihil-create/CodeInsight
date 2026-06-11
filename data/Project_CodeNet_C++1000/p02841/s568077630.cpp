#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int ans = d2==1 ? 1 : 0;
    cout << ans << endl;

    return 0;
}
