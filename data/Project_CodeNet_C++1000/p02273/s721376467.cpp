#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = -100100100;
// const int M = 1000000007;
const int M = 1046527;
typedef tuple<int,int, int> P;


struct point{
    double x,y;
    point operator-(const point p1){
        point res(*this);
        double rx,ry;
        rx = res.x-p1.x;
        ry = res.y-p1.y;
        point pp;
        pp.x = rx;pp.y=ry;
        return pp;
    }
};
typedef pair<point,point> PP;

void cosh(int n, point p1, point p2){
    if(n==0){
        
        
        return;
    }
    point s,u,t;
    double length = sqrt(pow(std::abs(p1.x-p2.x),2)+pow(std::abs(p1.y-p2.y),2))/3;
    // s.x += length;s.y += length;
    // 行列の演算を行う
    double th = M_PI*60/180;
    s.x=(2*p1.x+p2.x)/3;
    s.y=(2*p1.y+p2.y)/3;
    t.x=(p1.x+2*p2.x)/3;
    t.y=(p1.y+2*p2.y)/3;
    u.x = (cos(th))*(t.x-s.x) -sin(th)*(t.y-s.y) + s.x;
    u.y = (sin(th))*(t.x-s.x) + (cos(th))*(t.y-s.y) + s.y;
    
    cosh(n-1,p1,s);
    printf("%.10f %.10f\n", s.x, s.y);
    cosh(n-1,s,u);
    printf("%.10f %.10f\n", u.x, u.y);
    cosh(n-1,u,t);
    printf("%.10f %.10f\n", t.x, t.y);
    cosh(n-1,t,p2);
}

int main(){
    int n;
    cin >> n;
    point p1,p2;
    p1.x=0;p1.y=0;
    p2.x=100;p2.y=0;
    printf("%.8f %.8f\n", p1.x, p1.y);
    cosh(n,p1,p2);
    printf("%.8f %.8f\n", p2.x, p2.y);
    return 0;
}
