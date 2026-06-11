#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> ps;
    for(int i=0, j=n-1; i <= j;)
    {
        while(i<n && s.at(i) != 'L') i++;
        while(j>=0 && s.at(j) != 'L') j--;
        if(i > j) break;
        ps.push_back(make_pair(i, j));
        while(i<n && s.at(i) == 'L') i++;
        while(j>=0 && s.at(j) == 'L') j--;
        if(i > j) break;
        ps.push_back(make_pair(i, j));
    }
    // for(int i=0; i<ps.size(); i++) cout << ps.at(i).first << ", " << ps.at(i).second << endl;

    for(int i=0; i<k; i++)
    {
        if(ps.empty()) break;
        pair<int, int> p = ps.back();
        ps.pop_back();
        if(s.at(p.first) == 'L')
        {
            s.erase(p.first, p.second-p.first+1);
            s.insert(p.first, string(p.second-p.first+1, 'R'));
        }
        else if(s.at(p.first) == 'R')
        {
            s.erase(p.first, p.second-p.first+1);
            s.insert(p.first, string(p.second-p.first+1, 'L'));
        }
    }
    // cout << s << endl;

    int ans = 0;
    char c = s.front();
    for(int i=1; i<n; i++)
    {
        if(s.at(i) == c) ans++;
        else c = s.at(i);
    }
    cout << ans << endl;

    return 0;
}
