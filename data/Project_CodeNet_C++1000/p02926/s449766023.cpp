#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }


int main(){
    int N;
    cin >> N;
    vector<pair<long long, long long>> xy(N);
    REP(i, N) cin >> xy[i].first >> xy[i].second;
    vector<pair<long long, long long>> v;
    REP(i, N){
        long long x = xy[i].first;
        long long y = xy[i].second;
        v.push_back(make_pair(x, y));
        v.push_back(make_pair(-y, x));
        v.push_back(make_pair(-x, -y));
        v.push_back(make_pair(y, -x));
        v.push_back(make_pair(x-y, x+y));
        v.push_back(make_pair(-x-y, x-y));
        v.push_back(make_pair(-x+y, -x-y));
        v.push_back(make_pair(x+y, -x+y));
    }
    REP(i, N) REP(j, N){
        v.push_back(make_pair(v[i].first+v[j].first, v[i].second+v[j].second));
    }

    long long ans = 0;
    for(auto zz : v){
        long long a = zz.first;
        long long b = zz.second;
        long long x = 0, y = 0;
        for(auto z : xy){
            long long xx = z.first;
            long long yy = z.second;
            if(a*xx+b*yy > 0){
                x += xx;
                y += yy;
            }
        }
        ans = max(ans, x*x+y*y);
    }
    cout << fixed << setprecision(32) << sqrt(ans) << endl;
    return 0;
}