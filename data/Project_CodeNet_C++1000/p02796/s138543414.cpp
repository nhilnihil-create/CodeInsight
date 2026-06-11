#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> sls(n);
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        sls.at(i) = make_pair(a-b, a+b);
    }
    sort(sls.begin(), sls.end(), comp);

    int res = 1;
    int cp = sls.at(0).second;
    for(auto &sl : sls)
    {
        if(sl.first >= cp)
        {
            res++;
            cp = sl.second;
        }
    }
    cout << res << '\n';


    return 0;
}