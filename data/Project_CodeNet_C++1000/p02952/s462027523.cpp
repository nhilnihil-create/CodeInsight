#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    int ans = 0, inf = 1, sup = 10;

    while(n >= sup){
        ans += (sup - inf);
        inf = inf * 100;
        sup = sup * 100;
    }
    if(n >= inf) ans += (n - inf) + 1;

    cout << ans << endl;
    return 0;
}
