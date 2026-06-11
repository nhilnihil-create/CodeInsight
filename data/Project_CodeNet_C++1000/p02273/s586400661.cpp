#include<iostream>
#include<cmath>

struct Point{
    double x;
    double y;
};

Point s_func(Point p,Point q){
    Point s = {(2*p.x+q.x)/3,(2*p.y+q.y)/3};
    return s;
}

Point t_func(Point p,Point q){
    Point s = {(p.x+2*q.x)/3,(p.y+2*q.y)/3};
    return s;
}

Point u_func(Point s,Point t){
    double r=M_PI/3;
    Point u;
    u.x = (t.x-s.x)*cos(r)-(t.y-s.y)*sin(r)+s.x;
    u.y = (t.x-s.x)*sin(r)+(t.y-s.y)*cos(r)+s.y;
    
    return u;
}

void kock(int n,Point p1,Point p2){
    if(n==0){
        std::cout << p2.x << ' ' << p2.y <<'\n';
        return;
    }
    
    Point s,t,u;
    s = s_func(p1,p2);
    t = t_func(p1,p2);
    u = u_func(s,t);
    
    kock(n-1,p1,s);
    kock(n-1,s,u);
    kock(n-1,u,t);
    kock(n-1,t,p2);
}
    
    
int main(){
    Point p1 = {0,0},p2 = {100,0};
    int n;
    std::cin >> n;
    std::cout << p1.x << ' ' << p1.y << '\n';
    kock(n,p1,p2);
    return 0;
}

