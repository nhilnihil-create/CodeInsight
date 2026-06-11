#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t a, b, c, k, sum = 0;
    cin >> a >> b >> c >> k;
    if (a >= k )sum = k;
    else if (a + b >= k)sum = a;
    else{
        sum = a - (k - a - b);
    }
    cout << sum << '\n';
    return 0;
}