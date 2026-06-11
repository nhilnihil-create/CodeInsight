#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<double, double>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;

double dist (double a, double b) {
    return sqrt(a*a+b*b);
}

int main(){
    int n;
    cin >> n;
    vector<P> e(n);
    rep(i, n) cin >> e[i].first >> e[i].second;
    auto comp = [](P a, P b) {
        return atan2(a.second, a.first)<atan2(b.second, b.first);
    };
    sort(e.begin(), e.end(), comp);
    vector<double> theta(2*n);
    rep(i, n) {
        theta[i] = atan2(e[i].second, e[i].first);
        theta[i+n] = theta[i] + 2*M_PI;
    }
    double ans = 0.0;

    rep(i, n) {
        rep(j, n) {
            //double ang = theta[i];
            //ang += M_PI;
            double sumx = 0.0;
            double sumy = 0.0;
            int id = i;
            int k = j;
            if (k<id) k+=n;
            while (id<=k) {
                sumx += e[id%n].first;
                sumy += e[id%n].second;
                id++;
            }
            ans = max(ans, dist(sumx, sumy));
        }
    }
    
    
    
    printf("%.15lf\n", ans);
    return 0;
}
