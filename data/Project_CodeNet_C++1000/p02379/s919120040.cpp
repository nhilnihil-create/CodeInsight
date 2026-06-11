#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double answer,x1,x2,y1,y2,a,b;
    cin >> x1 >> y1 >> x2 >> y2;

    a = pow(x1 - x2, 2.0);
    b = pow(y1 - y2, 2.0);
    answer = sqrt(a + b);
    //cout << answer << endl;

    printf("%lf\n",answer);  

    return 0;

}
