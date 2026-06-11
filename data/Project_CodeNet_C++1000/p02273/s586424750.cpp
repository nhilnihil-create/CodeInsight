#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#define out(xxx) printf("%.10lf %.10lf\n",xxx.first,xxx.second)
using namespace std;
typedef pair<double,double> P;
const double theta = 60.0*M_PI/180.0;

void Koch_Curve(P st, P go, int n){
    if(n == 0) return;
    
    double stx = st.first;
    double sty = st.second;
    double gox = go.first;
    double goy = go.second;

    P s;
    s.first = (2.0*stx + gox )/3.0;
    s.second = (2.0*sty + goy)/3.0;
    P t;
    t.first = (stx + 2.0*gox)/3.0;
    t.second = (sty + 2.0*goy)/3.0;

    double vx = t.first - s.first;
    double vy = t.second - s.second;

    P u;
    u.first = vx*cos(theta) - vy*sin(theta) + s.first; 
    u.second = vx*sin(theta) + vy*cos(theta) + s.second; 
    
    Koch_Curve(st,s,n-1);
    out(s);
    Koch_Curve(s,u,n-1);
    out(u);
    Koch_Curve(u,t,n-1);
    out(t);
    Koch_Curve(t,go,n-1);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    P s,g;
    s.first = 0.0, s.second = 0.0;
    g.first = 100.0, g.second = 0.0;
    out(s);
    Koch_Curve(s,g,n);
    out(g);

    return 0;
}

