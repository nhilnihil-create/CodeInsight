#include <bits/stdc++.h>
#include <math.h>
using namespace std;


pair<double,double> u_search(pair<double,double> x,pair<double,double> y){
    double rad60 = M_PI * 60.0 / 180.0;
    double sin60 = sin(rad60),cos60 = cos(rad60);
    pair<double,double> dif = make_pair(y.first - x.first,y.second - x.second);
    double kaiten_x = dif.first * cos60 - dif.second * sin60;
    double kaiten_y = dif.first * sin60 + dif.second * cos60;
    pair<double,double> u = make_pair(y.first + kaiten_x,y.second+kaiten_y);
    return u;
}


void korh(pair<double,double>p1,pair<double,double>p2,int n,int count){
    count++;
    if(count <= n){
        pair<double,double> s,u,t;
        s.first = (p1.first * 2.0 + p2.first * 1.0) / 3.0;
        s.second = (p1.second * 2.0 + p2.second * 1.0) / 3.0;
        korh(p1,s,n,count);
        printf("%.8f %.8f\n",s.first,s.second);
        u = u_search(p1,s);
        korh(s,u,n,count);
        printf("%.8f %.8f\n",u.first,u.second);
        t.first = (p1.first * 1.0 + p2.first * 2.0) / 3.0;
        t.second = (p1.second * 1.0 + p2.second * 2.0) / 3.0;
        korh(u,t,n,count);
        printf("%.8f %.8f\n",t.first,t.second);
        korh(t,p2,n,count);
    }
}



int main(){
    int n;
    cin >> n;
    pair<double,double> p1 = make_pair(0,0);
    pair<double,double> p2 = make_pair(100,0);
    int count = 0;
    printf("%.8f %.8f\n",p1.first,p1.second);
    korh(p1,p2,n,count);
    printf("%.8f %.8f\n",p2.first,p2.second);
}
