#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i-1] == s[i]) continue;
        else ans++;
    }
    cout << ans << endl;
}