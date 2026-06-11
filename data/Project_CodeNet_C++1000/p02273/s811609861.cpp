#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iomanip>
#include <cmath>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

struct Point{
    double x;
    double y;
};

void koch(int n,Point s,Point e){
    if(n==0){
        cout << std::setprecision(8) << e.x<<" "<<e.y << endl;
    }else{
        Point tmp_p1,tmp_p2,tmp_p3;
        tmp_p1.x = (s.x * 2.0) / 3.0 + (e.x) / 3.0;
        tmp_p1.y = (s.y * 2.0) / 3.0 + (e.y) / 3.0;
        koch(n - 1, s, tmp_p1);
        tmp_p2.x = (s.x) / 3.0 + (e.x*2.0) / 3.0;
        tmp_p2.y = (s.y) / 3.0 + (e.y*2.0) / 3.0;
        tmp_p3.x = tmp_p1.x + (((tmp_p2.x - tmp_p1.x) * cos(M_PI/3.0)) - ((tmp_p2.y - tmp_p1.y)*sin(M_PI/3.0)));
        tmp_p3.y = tmp_p1.y + (((tmp_p2.x - tmp_p1.x) * sin(M_PI/3.0)) + ((tmp_p2.y - tmp_p1.y)*cos(M_PI/3.0)));

        koch(n - 1, tmp_p1, tmp_p3);
        koch(n - 1, tmp_p3, tmp_p2);
        koch(n - 1, tmp_p2, e);
    }
}

int main(){

    int n;
    cin>>n;
    std::cout << std::fixed<< std::setprecision(8)<<0.0<<" "<<0.0<<endl;
    Point start = {0, 0},end={100,0};
    koch(n, start, end);
    return 0;
}
