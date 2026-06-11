//
//  main.cpp
//  koch_curve
//
//  Created by ???????????? on 2017/10/07.
//  Copyright ?? 2017 ????????????. All rights reserved.
//

#include <iostream>
#include <stdio.h>
//#include <cmath>
#include <iomanip>
#include <math.h>

//#define PI 3.14159265

using namespace std;

double param = 60.0*M_PI/180.0;

struct P {
    double x;
    double y;
};


void print(P p){
//    cout << setprecision(10) << p.x << " " <<setprecision(10)<< p.y << endl;
    printf("%.8f %.8f\n", p.x, p.y);
}

void koch(int n, P p1, P p2){
    if(n == 0) return;
    
    P s, u, t;
    s.x = (2*p1.x + p2.x)/3;
    s.y = (2*p1.y + p2.y)/3;
    
    t.x = (p1.x + 2*p2.x)/3;
    t.y = (p1.y + 2*p2.y)/3;
    
    u.x = (t.x-s.x)*cos(param) - (t.y-s.y)*sin(param) + s.x;
    u.y = (t.x-s.x)*sin(param) + (t.y-s.y)*cos(param) + s.y;
    
    koch(n-1, p1, s);
    print(s);
//    cout << s.x << " "<< s.y<< endl;
    koch(n-1, s, u);
    print(u);
//    cout << u.x << " "<< u.y<< endl;
    koch(n-1, u, t);
    print(t);
//    cout << t.x << " "<< t.y<< endl;
    koch(n-1, t, p2);
    
    
}




int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    P p1, p2;
    
    p1.x = 0.0;
    p1.y = 0.0;
    
    p2.x = 100.0;
    p2.y = 0.0;
    
    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);

    return 0;
}