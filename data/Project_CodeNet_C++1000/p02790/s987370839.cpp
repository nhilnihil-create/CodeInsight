#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    char m = '0' + min(a, b);
    string ans(max(a, b), m);
    cout << ans << endl;
    return 0;
}
