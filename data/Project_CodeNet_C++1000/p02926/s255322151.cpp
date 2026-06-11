#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
    vector<pair<int,int>> v;
    int n;
    cin >> n;

    long long x,y;
    for(int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        if(x != 0 || y != 0)
            v.emplace_back(x,y);   
    }
    sort(v.begin(),v.end(), [&] (auto &p, auto &q) {
        return atan2(p.second,p.first) < atan2(q.second,q.first);
    });

    n = v.size();
    v.insert(v.end(),v.begin(),v.end());
    long long ans = 0;
    for(int i =0; i < n; ++i)
    {
        x = 0; y = 0;
        for(int j = i; j < n + i; ++j)
        {
            x+=v[j].first; y+=v[j].second;
            ans = max(ans,x*x + y*y);
        }
    }
    cout << setprecision(16) << sqrt(ans) << '\n';
    return 0;
}