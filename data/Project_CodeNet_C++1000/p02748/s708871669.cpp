#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> inline bool chmin(T &a, T b)
{
    if(a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> as(a);
    for(int i=0; i<a; i++) cin >> as.at(i);
    vector<int> bs(b);
    for(int i=0; i<b; i++) cin >> bs.at(i);
    vector<vector<int>> xycs(m);
    for(int i=0; i<m; i++)
    {
        vector<int> xyc(3);
        for(int i=0; i<3; i++) cin >> xyc.at(i);
        xycs.at(i) = xyc;
    }

    int ma = *min_element(as.begin(), as.end());
    int mb = *min_element(bs.begin(), bs.end());
    int mcos = ma + mb;
    for(auto xyc : xycs)
    {
        chmin(mcos, as.at(xyc.at(0)-1) + bs.at(xyc.at(1)-1) - xyc.at(2));
    }
    cout << mcos << '\n';

    return 0;
}
