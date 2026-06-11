#include<bits/stdc++.h>
/*
alias g='g++ -std=c++17 -O2 pra.cpp'
cd programming
cd cpp
cd practice

*/
using namespace std;
double PI = acos(-1);
struct point{
    double x;
    double y;
};
void kock(int n, point p1, point p2){
    if (n == 0) return;
    point s, t, u;//再帰的に座標を計算
    s.x=((p1.x/3.0)*2.0)+(p2.x/3.0);
    s.y=((p1.y/3.0)*2.0)+(p2.y/3.0);
    t.x=((p2.x/3.0)*2.0)+(p1.x/3.0);
    t.y=((p2.y/3.0)*2.0)+(p1.y/3.0);
    u.x = (t.x - s.x)* cos(PI/3.0) - (t.y - s.y)* sin(PI/3.0) + s.x;
    u.y = (t.x - s.x)* sin(PI/3.0) + (t.y - s.y)* cos(PI/3.0) + s.y;
    kock(n-1, p1, s);
    printf("%.6f %.6f\n", s.x, s.y);
    kock(n-1, s, u);
    printf("%.6f %.6f\n", u.x, u.y);
    kock(n-1, u, t);
    printf("%.6f %.6f\n", t.x, t.y);
    kock(n-1, t, p2);
}//uはsを基準にtを60度回転させたもの
int main(){
    int n; cin >> n;
    printf("%.6f %.6f\n", 0.0000000, 0.0000000);
    point def, last;
    def.x = 0.0;
    def.y = 0.0;
    last.x = 100.0;
    last.y = 0.0;
    kock(n, def, last);
    printf("%.6f %.6f", 100.000000, 0.0000000);
    return 0;
}
