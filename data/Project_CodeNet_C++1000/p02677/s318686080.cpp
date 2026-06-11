#include<bits/stdc++.h>
using namespace std;

int main(){
    //先端の座標
    double x1, y1, x2, y2;
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    x1=A*cos( (2*M_PI)*((double)(H*60+M)/720) );
    y1=A*sin( (2*M_PI)*((double)(H*60+M)/720) );

    x2=B*cos( (2*M_PI)*((double)(M)/60) );
    y2=B*sin( (2*M_PI)*((double)(M)/60) );

    printf("%.15f", sqrt(pow(x1-x2, 2)+pow(y1-y2, 2)));    
}