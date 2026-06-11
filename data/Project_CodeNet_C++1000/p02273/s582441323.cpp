#include <bits/stdc++.h>
using namespace std;

//pair<double,double> s,t,u;

void koch(int d,pair<double,double> p1,pair<double,double> p2){
    pair<double,double> s,t,u;
    if(d == 0) return;
    s.first = (2*p1.first + p2.first)/3;
    s.second = (2*p1.second + p2.second)/3;
    t.first = (p1.first + 2*p2.first)/3;
    t.second = (p1.second + 2*p2.second)/3;
    u.first = (t.first - 1.7320508*t.second +s.first + 1.7320508*s.second)/2;
    u.second = (1.7320508*t.first + t.second - 1.7320508*s.first + s.second)/2;
    koch(d-1,p1,s);
    cout << s.first << " " << s.second << endl;
    koch(d-1,s,u);
    cout << u.first << " " << u.second << endl;
    koch(d-1,u,t);
    cout << t.first << " " << t.second << endl;
    koch(d-1,t,p2);
}

int main(){
    int n;
    pair<double,double> p1(0,0);
    pair<double,double> p2(100,0);
    cin >> n;
    cout << p1.first << " " << p1.second << endl;
    koch(n,p1,p2);
    cout << p2.first << " " << p2.second << endl;
    return 0;
}

