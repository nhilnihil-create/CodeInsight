#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#define MAX 10000


struct Point{
    double x;
    double y;
};

double p[MAX][2];
int ip = 0;

void input_p(Point p0){
    p[ip][0] = p0.x;
    p[ip][1] = p0.y;
    ip += 1;
}

int kock(int n, Point p1, Point p2){
    if(n == 0){
        return 0;
    }
    else{
        Point s, t, u;
        s.x = (2*p1.x + 1*p2.x) / 3.0;
        s.y = (2*p1.y + 1*p2.y) / 3.0;
        t.x = (1*p1.x + 2*p2.x) / 3.0;
        t.y = (1*p1.y + 2*p2.y) / 3.0;
        u.x = (t.x - s.x)*(1.0/2.0) - (t.y - s.y)*(sqrt(3)/2.0) + s.x;
        u.y = (t.x - s.x)*(sqrt(3)/2.0) + (t.y - s.y)*(1.0/2.0) + s.y;

        kock(n-1, p1, s);
        input_p(s);
        kock(n-1, s, u);
        input_p(u);
        kock(n-1, u, t);
        input_p(t);
        kock(n-1, t, p2);
    }
}

int main(){
    int n;
    std::cin >> n;
    Point p1;
    p1.x = 0.0; p1.y = 0.0;
    Point p2;
    p2.x = 100.0; p2.y = 0.0;
    input_p(p1);
    kock(n, p1, p2);
    input_p(p2);
    for(int i=0; i<ip; i++){
        printf("%.8lf %.8lf\n", p[i][0], p[i][1]);
    }
    return 0;
}
