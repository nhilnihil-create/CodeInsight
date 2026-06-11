#include<iostream>

using namespace std;

int main()
{
    long long int a, b, c,d,x,y, re;
    cin >> a >>b >> c >>d;
    a*c>a*d? x=a*c: x=a*d;
    b*c>b*d? y= b*c: y= b*d;
    x>y? re=x: re=y;
    cout << re;
}
