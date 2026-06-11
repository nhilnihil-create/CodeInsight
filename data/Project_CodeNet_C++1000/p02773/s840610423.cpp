#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<string, int> m;
vector<pair<int, string>> v;
vector<string> ans;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        m[s]++;
    }

    for (auto x : m)
    {
        v.push_back(make_pair(x.second, x.first));
    }
    sort(v.begin(), v.end());

    /*
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    */

    int index = v.size() - 1;
    while (index >= 0 && v[index].first == v[v.size() - 1].first)
    {
        ans.push_back(v[index].second);
        index--;
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}