#include <iostream>

using namespace std;

long long a, ans;
int f(int idx) {
    if(idx == 1)
        return ans = a;

    ans = (ans * f( idx / 2) ) % 1000000007;

    if(idx % 2)
        ans = ( ans * a ) % 1000000007;

    return ans;
}
int main() {
    int b;
    while(cin >> a >> b) {
        ans = 1;
        a = a % 1000000007;
        cout << f(b) << "\n";
    }
    return 0;
}
