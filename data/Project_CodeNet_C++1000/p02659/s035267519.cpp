#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t A, ans, B_dashdash;
    double B, B_dash;

    cin >> A >> B;

    B_dash = B * 100 + 0.1;

    B_dashdash = B_dash;

    ans = (A * B_dashdash) / 100;

    cout << ans << endl;

    return 0;
}