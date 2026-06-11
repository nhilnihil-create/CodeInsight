#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string,int> mp;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    long long int ans = 0;
    for (auto& p : mp) {
        int s = p.second;
        ans += (long long int)s*(s-1)/2;
    }

    cout << ans << endl;
    
    return 0;
}