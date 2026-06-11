#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> P;

int n;

P naibun(P p1, P p2, double r) { // p1 と p2をr:1-rに内分する点
    P dp = P(p2.first - p1.first, p2.second - p1.second);
    return P(p1.first + r * dp.first, p1.second + r * dp.second);
}

P tri(P p1, P p2) { // p1を中心としp2を60度半時計回りに回転させた点
    P dp = P(p2.first - p1.first, p2.second - p1.second);
    P ndp = P(dp.first / 2 - (sqrt(3) / 2.0) * dp.second,
              dp.second / 2 + (sqrt(3) / 2.0) * dp.first);
    return P(p1.first + ndp.first, p1.second + ndp.second);
}

vector<P> koch_curve(P p1, P p2, int n) {
    vector<P> res;
    if(n >= 1) {
        P np1 = naibun(p1, p2, 1.0 / 3.0);
        P np3 = naibun(p1, p2, 2.0 / 3.0);
        P np2 = tri(np1, np3);

        vector<P> v1 = koch_curve(p1, np1, n - 1);
        vector<P> v2 = koch_curve(np1, np2, n - 1);
        vector<P> v3 = koch_curve(np2, np3, n - 1);
        vector<P> v4 = koch_curve(np3, p2, n - 1);

        for(int i = 0; i < v1.size(); i++)
            res.push_back(v1[i]);
        res.push_back(np1);
        for(int i = 0; i < v2.size(); i++)
            res.push_back(v2[i]);
        res.push_back(np2);
        for(int i = 0; i < v3.size(); i++)
            res.push_back(v3[i]);
        res.push_back(np3);
        for(int i = 0; i < v4.size(); i++)
            res.push_back(v4[i]);
    }
    return res;
}

int main() {
    cin >> n;
    P p1 = P(0.0, 0.0);
    P p2 = P(100.0, 0.0);
    vector<P> ans;
    ans.push_back(p1);
    vector<P> koch = koch_curve(p1, p2, n);
    for(int i = 0; i < koch.size(); i++)
        ans.push_back(koch[i]);

    ans.push_back(p2);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
