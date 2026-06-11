#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = 0;
    while (B-1>0)
    {
        B -= A-1;
        ans++;
    }
    cout << ans << endl;
    

    return 0;
}