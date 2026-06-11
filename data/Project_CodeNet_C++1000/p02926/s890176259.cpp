#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector< pair<int,int> > p(N);
    for(int i=0; i<N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), [](auto &lhs, auto &rhs) {return atan2(lhs.first, lhs.second) < atan2(rhs.first, rhs.second);});
    for(int i=0; i<N; i++) {
        p.push_back(p[i]);
    }

    double ans = 0.0;
    for(int i=0; i<N; i++) {
        pair<int,int> sum = make_pair(0, 0);
        for(int j=i; j<i+N; j++) {
            sum.first += p[j].first;
            sum.second += p[j].second;
            double tmp = hypot(sum.first, sum.second);
            ans = max(ans, tmp);
        }
    }

    printf("%.15lf\n", ans);
    return 0;
}
