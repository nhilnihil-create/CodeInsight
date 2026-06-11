#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int k, x;
    cin >> k >> x;
    if(500 * k >= x) puts("Yes");
    else puts("No");

    return 0;
}
