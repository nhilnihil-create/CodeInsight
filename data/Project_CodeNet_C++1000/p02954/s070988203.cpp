#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    string s;
    cin >> s;
    map<char, int> mp{{'L', -1}, {'R', 1}};
    vector<int> ans(s.size(), 0);

    for (int i = 0; i < s.size(); i++) {
        int t = i, cnt = 1;
        char now = s[i];
        int m = mp[now];
        while(now == s[t + m]) {
            t += m;
            cnt++;
        }
        if (cnt % 2 == 0) ans[i + m * cnt]++;
        else ans[i + m * (cnt - 1)]++;
    }


    for (int i = 0; i < s.size(); i++) cout << ans[i] << ' ';
    cout << endl;
}