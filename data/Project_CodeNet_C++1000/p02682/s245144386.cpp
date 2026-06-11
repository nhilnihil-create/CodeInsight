// ABC167B.cpp

#include <iostream>
using namespace std;
int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if (a >= k) { // 1のカードがたくさんある時
        ans = k;
        cout << ans << endl;
        return 0;
    }
    else { // 1のカードがあまりない時
        ans = a;
        k -= a;
    }
    if (b < k) { // 0のカードを使う
        k -= b;
        ans -= k; // 0のカードがなくなったら、-1のカードを使う
    }
    cout << ans << endl;
    return 0;
}
