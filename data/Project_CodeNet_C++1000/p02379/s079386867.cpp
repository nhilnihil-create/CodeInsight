#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

typedef struct{
    double x,y;
}Point;

int main()
{

    Point p1,p2;

    cin>>p1.x>>p1.y>>p2.x>>p2.y;

    cout<<fixed<<setprecision(5)<<sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))<<endl;

    return 0;
}

