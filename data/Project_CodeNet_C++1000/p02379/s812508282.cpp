#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x1,x2,y1,y2,s;
    cin >> x1 >> y1 >> x2 >> y2;
    s = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("%9.7f",s);
}
