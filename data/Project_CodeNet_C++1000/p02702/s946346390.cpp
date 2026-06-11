#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    FASTIO
    string s;
    cin >> s;
    int n = s.size();
    int suffix = 0;
    int power_of_ten = 1;
    vector<int> cnt(2019,0);
    cnt[0]++;
    long long ans = 0;
    for(int i=n-1; i>=0; i--)
    {
        int d = s[i]-'0';
        suffix = (suffix + power_of_ten*d)%2019;
        power_of_ten = 10*power_of_ten%2019;
        ans += cnt[suffix];
        cnt[suffix]++;
    }
    cout << ans << "\n";
    return 0;
}