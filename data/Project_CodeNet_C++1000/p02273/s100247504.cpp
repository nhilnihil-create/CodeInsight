#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iomanip>

typedef std::pair<double, double> point;

point hoge(point q2, point q4){
    point q3;
    point r = std::make_pair((q2.first + q4.first)/2, (q2.second + q4.second)/2);
    point vec = std::make_pair(-(q4.second - q2.second), q4.first - q2.first);
    q3 = std::make_pair(r.first + vec.first * sqrt(3)/2, r.second + vec.second * sqrt(3)/2);
    return q3;
}

void kochCurve(point p1, point p2, int i, int n){
    if(i == n){
        std::cout << std::setprecision(8) << p1.first << " " << p1.second << std::endl;
        //std::cout << p2.first << " " << p2.second << std::endl;
        return;
    }
    if(i > n){
        std::cout << "something wrong";
        return;
    }
    point q1 = std::make_pair(p1.first, p1.second);
    point q2 = std::make_pair(p1.first * 2/3 + p2.first * 1/3, p1.second * 2/3 + p2.second * 1/3);
    kochCurve(q1, q2, i + 1, n);
    point q4 = std::make_pair(p1.first * 1/3 + p2.first * 2/3, p1.second * 1/3 + p2.second * 2/3);    
    point q3 = hoge(q2, q4);   
    kochCurve(q2, q3, i + 1, n);
    kochCurve(q3, q4, i + 1, n);
    kochCurve(q4, p2, i + 1, n);
}

int main(){
    int n;
    scanf("%d", &n);
    int i = 0;
    std::cout << std::fixed;
    point start = std::make_pair(0.0, 0.0);
    point end = std::make_pair(100.0, 0.0);
    kochCurve(start, end, i, n);
    std::cout << end.first << " " << end.second << std::endl;
    return 0;
}
