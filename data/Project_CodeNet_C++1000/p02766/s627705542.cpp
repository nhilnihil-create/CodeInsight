#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string ans;
    while (n) {
        char ch = (n%k) + '0';
        ans = ch + ans;
        n /= k;
    }
    cout << ans.length() << "\n";
    return 0;
}