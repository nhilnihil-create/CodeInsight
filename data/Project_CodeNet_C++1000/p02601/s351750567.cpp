#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int cc = 0;
    if(b <= a) {
        cc = floor(log2(a/b)) + 1;
        b *= pow(2, cc);
    }
    if(c <= b)
        cc += floor(log2(b/c)) + 1;
    if(cc <= k) cout << "Yes";
    else cout << "No";
    return 0;
}
