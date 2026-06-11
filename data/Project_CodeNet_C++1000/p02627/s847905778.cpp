#include <bits/stdc++.h>
#define in(x) freopen(x, "r", stdin)
#define out(x) freopen(x, "w", stdout)
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
                
    #ifndef _LOCAL          
    #endif // _LOCAL

    char c;
    cin >> c;
    if (c >= 'A' && c <= 'Z') cout << "A\n";
        else cout << "a\n";

    return 0;
}