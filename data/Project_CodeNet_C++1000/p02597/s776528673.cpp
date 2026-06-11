#include <iostream>
using namespace std;
int main()
{
    int n, r_cnt = 0, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        r_cnt += (s[i] == 'R' ? 1 : 0);
    }
    for (int i = 0; i < r_cnt; i++) {
        ans += (s[i] == 'W' ? 1 : 0);
    }
    cout << ans << endl;
    return 0;
}