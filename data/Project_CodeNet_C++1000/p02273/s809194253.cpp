//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<long double, long double>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

inline long double leng2(double x1, double y1, double x2, double y2) {return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}

P ue(P x, P y) {
    P n;
    n.first = (x.first + y.first)/2;
    n.second = (x.second + y.second)/2;
    long double le = leng2(x.first, x.second, y.first, y.second);
    n.first += (x.second - y.second)/6*sqrt(3.0);
    n.second += (y.first - x.first)/6*sqrt(3.0);
    return n;
}

int main() {
    int n;
    cin >> n;

    function<vector<P>(int, P, P)> dfs = [&](int i, P x, P y ) {
        if(!i) {
            vector<P> vec;
            vec.push_back(x);
            vec.push_back(y);
            return vec;
        }
        --i;
        P i1, i2;
        i1.first = (x.first*2 + y.first)/3;
        i1.second = (x.second*2 + y.second)/3;
        i2.first = (x.first + y.first*2)/3;
        i2.second = (x.second + y.second*2)/3;

        

        vector<P> vec(1, x), vec1 = dfs(i, x, i1), vec2 = dfs(i, i2, y), vec3 = dfs(i, i1, ue(x, y)), vec4 = dfs(i, ue(x, y), i2);
        rep(j, vec1.size()-1) {
            vec.push_back(vec1[j+1]);
        }
        rep(j, vec1.size()-1) {
            vec.push_back(vec3[j+1]);
        }
        rep(j, vec1.size()-1) {
            vec.push_back(vec4[j+1]);
        }
        rep(j, vec1.size()-1) {
            vec.push_back(vec2[j+1]);
        }
        return vec;
    };

    P x = make_pair(0, 0), y = make_pair(100, 0);
    vector<P> vv = dfs(n, x, y);

    cout << fixed << setprecision(10);
    rep(i, vv.size()) {
        cout << vv[i].first << ' ' << vv[i].second << endl;
    }
}
