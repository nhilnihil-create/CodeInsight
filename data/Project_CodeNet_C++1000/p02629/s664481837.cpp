#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    string ans;
    while (n > 0) {
        n--;
        ans += ((char)('a' + n % 26));
        n /= 26;
    }
    for (long long i = ans.length() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
