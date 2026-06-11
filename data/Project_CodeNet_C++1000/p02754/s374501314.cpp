#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    long long a;
    long long b;
    cin >> n >> a >> b;
    if(a == 0){
        cout << 0 << endl;
        return 0;
    }
    long long time = n/(a + b);
    long long ans = time * a + min((n % (a + b)),a);
    cout << ans << endl;
}