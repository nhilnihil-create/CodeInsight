#include <bits/stdc++.h>
using namespace std;

#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

struct vec {
    double x, y;
    vec() : x(0), y(0) {}
    vec(double x, double y) : x(x), y(y) {}

    double len() const {
        return sqrt(pow(this->x,2.0) + pow(this->y,2.0));
    }

    vec& operator+=(const vec a) {
        this->x += a.x;
        this->y += a.y;
        return *this;
    }
    vec operator+(const vec a) const {
        vec res(*this);
        return res += a;
    }
    double angle() const {
        return atan2(this->x, this->y);
    }
    bool operator>(const vec a) const {
        return this->angle() > a.angle();
    }
    bool operator<(const vec a) const {
        return this->angle() < a.angle();
    }
};
using vv = vector<vec>;
using vvv = vector<vv>;

int main() {
    int N; cin >> N;
    vv v(N);
    rep(i,N) {
        double x, y; cin >> x >> y;
        v[i] = vec(x, y);
    }

    sort(v.begin(), v.end());
    double ans = 0;
    rng(k,1,N+1) rep(i,N) {
        vec sum;
        rng(j,i,i+k) {
            sum += v[j%N];
        }
        chmax(ans, sum.len());
    }

    printf("%.12lf\n", ans);
    return 0;
}
