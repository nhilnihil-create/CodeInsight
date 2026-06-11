#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
    Point() : x(0), y(0) {}
    Point(ll x, ll y) : x(x), y(y) {}
    int quadrant() const {
        if(x == 0 && y == 0){
            return 0;
        }
        if(x >= 0){
            if(y >= 0){
                return 1;
            }else{
                return 4;
            }
        }else{
            if(y >= 0){
                return 2;
            }else{
                return 3;
            }
        }
    }

    Point& operator+=(const Point& other){
        x += other.x;
        y += other.y;
        return *this;
    }

    bool operator<(const Point& q) const {
        int qp = quadrant();
        int qq = q.quadrant();
        if(qp != qq){ return qp < qq; }
        return (x * q.y - y * q.x) > 0;
    }

    ll norm2() const {
        return x * x + y * y;
    }

    double norm() const {
        return sqrt((double)norm2());
    }
};

int main(){
    ll n;
    cin >> n;
    vector<Point> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p.at(i).x >> p.at(i).y;
    }
    sort(p.begin(), p.end());

    double ans = 0;
    for(int i = 0; i < p.size(); ++i){
        Point a;
        for(int j = 0; j < p.size(); ++j){
            a += p.at((i + j) % p.size());
            ans = max(ans, a.norm());
        }
    }
    printf("%.11f\n", ans);
    return 0;
}
