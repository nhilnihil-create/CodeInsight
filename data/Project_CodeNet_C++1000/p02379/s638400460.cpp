#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double x1,x2,y1,y2,s,dis;
    cin >> x1 >> y1 >> x2 >> y2;
    s=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    dis=sqrt(s);
    printf("%lf\n",dis);
    return 0;
}
 
