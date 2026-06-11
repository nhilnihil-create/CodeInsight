#include <iostream>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int h, n;
    cin >> h >> n;
    int ans = 0;
    rep(i,n) {
        int a;
        cin >> a;
        ans += a;
    }
    if(ans >= h) puts("Yes");
    else puts("No");

    return 0;
}
