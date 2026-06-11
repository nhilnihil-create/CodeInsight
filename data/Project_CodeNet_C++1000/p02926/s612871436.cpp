#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
using pii = pair<double, double>;

int main()
{
    int n;
    cin >> n;
    vector<pii> a;
    rep(i, 0, n)
    {
        double x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    auto comp = [=](pii xy1, pii xy2){
        return atan2(xy1.first, xy1.second) < atan2(xy2.first, xy2.second);
    };
    sort(a.begin(), a.end(), comp);

    vector<pii> vecs;
    vecs.emplace_back(0, 0);
    for (auto aa: a)
    {
        double x, y;
        tie(x, y) = vecs.back();
        vecs.emplace_back(x + aa.first, y + aa.second);
    }
    for (auto aa: a)
    {
        double x, y;
        tie(x, y) = vecs.back();
        vecs.emplace_back(x + aa.first, y + aa.second);
    }

    double ans = 0;
    rep(i, 0, n)
    rep(j, i, i + n)
    {
        double x, y;
        x = vecs[j + 1].first - vecs[i].first;
        y = vecs[j + 1].second - vecs[i].second;
        
        ans = max(ans, x * x + y * y);
    }

    double answer = sqrt((double)ans);
    printf("%.20f\n", answer);
    return 0;
}