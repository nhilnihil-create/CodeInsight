#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define PUSH(n,v) for(int i=0; i<(n); i++) {int j; cin >> j; v.push_back(j);}
#define ALL(v) v.begin(), v.end()

typedef pair<double, double> XY;

XY koch(XY p, XY q, double dist) {
    if (q.first > p.first) { // when you draw from left to right
        switch ((int)round(180.0 / acos(-1) * atan((p.second - q.second) / (p.first - q.first)))) {
            case 0:
                return make_pair((p.first + q.first) / 2, p.second + sqrt(3) / 2 * dist);
                break;
            case 60:
                return make_pair(p.first * 2 - q.first, q.second);
                break;
            case -60:
                return make_pair(q.first * 2 - p.first, p.second);
                break;
            default:
                break;
        }
    }else {
        switch ((int)round(180.0 / acos(-1) * atan((p.second - q.second) / (p.first - q.first)))) {
            case 0:
                return make_pair((p.first + q.first) / 2, p.second - sqrt(3) / 2 * dist);
                break;
            case 60:
                return make_pair(p.first * 2 - q.first, q.second);
                break;
            case -60:
                return make_pair(q.first * 2 - p.first, p.second);
                break;
            default:
                break;
        }
    }
    return make_pair(-1, -1);
}

void grow(vector<XY> &v, double dist) {
    for(int i = v.size()-1; i >= 1; i--) {
        XY p = v[i];
        XY q = v[i-1];
        XY pp, qq;
        pp = make_pair((p.first * 2 + q.first) / 3, (p.second * 2 + q.second) / 3);
        qq = make_pair((p.first + q.first * 2) / 3, (p.second + q.second * 2) / 3);
        XY pq = koch(qq, pp, dist);
        v.insert(v.begin() + i, pp);
        v.insert(v.begin() + i, pq);
        v.insert(v.begin() + i, qq);
    }
}

void printXY(vector<XY> v) {
    REP(i,v.size()) {
        printf("%.8f %.8f\n", v[i].first, v[i].second);
    }
}

int main() {
    int n;
    cin >> n;
    vector<XY> v;
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(100, 0));
    double dist = 100/3.;
    REP(i,n) {
        grow(v, dist);
        dist /= 3;
    }
    printXY(v);
    return 0;
}