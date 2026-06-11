#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double x1,y1,x2,y2,x,y,dis;

    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2){
        x = x1 - x2;
    }else{
        x = x2 - x1;
    }
    if(y1 > y2){
        y = y1 - y2;
    }else{
        y = y2 - y1;
    }

    cout << fixed;
    cout.precision(8);
    dis = sqrt(pow(x,2)+pow(y,2));
    cout << dis << endl;

    return 0;

}

