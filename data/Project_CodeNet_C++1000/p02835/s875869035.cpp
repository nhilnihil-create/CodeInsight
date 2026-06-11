#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if(a1 + a2 + a3 >= 22) puts("bust");
    else puts("win");

    return 0;
}
