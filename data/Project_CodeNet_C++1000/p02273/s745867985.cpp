#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1);

void koch(int n, pair<double,double> p1, pair<double,double> p2){
    if( n==0 )
        return;
    pair<double,double> s, t, u;
    double th = PI*60/180;

    s.first = (2.0*p1.first+ 1.0*p2.first)/3.0;
    s.second = (2.0*p1.second + 1.0*p2.second)/3.0;
    t.first = (1.0*p1.first+ 2.0*p2.first)/3.0;
    t.second = (1.0*p1.second + 2.0*p2.second)/3.0;
    u.first = (t.first - s.first)*cos(th) - (t.second-s.second)*sin(th)+s.first;
    u.second = (t.first - s.first)*sin(th) + (t.second-s.second)*cos(th)+s.second;

    koch(n-1,p1,s);
    cout << s.first << ' ' << s.second << endl;
    koch(n-1,s,u);
    cout << u.first << ' ' << u.second << endl;
    koch(n-1,u,t);
    cout << t.first << ' ' << t.second << endl;
    koch(n-1,t,p2);
}


int main()
{
    pair<double,double> a = make_pair(0,0);
    pair<double,double> b = make_pair(100,0);

    int n;
    cin >> n;
    cout << fixed << setprecision(10);
    cout << a.first << ' ' << a.second << endl;
    koch(n, a, b);
    cout << b.first << ' ' << b.second << endl;

    return 0;

}

