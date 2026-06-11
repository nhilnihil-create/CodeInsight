#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int a, b;
    cin >> a >> b;
    if(a > 9 || b > 9) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << a*b << endl;
    }

    return 0;
}
