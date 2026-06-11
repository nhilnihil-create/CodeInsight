#include<iostream>
using namespace std;
#include<cstdio>
int main()
{
    int x,y;
    cin >> x >> y ;
    cout << x/y << endl;
    cout << x%y << endl;
    printf("%.5lf",(double)x/y);
    return 0;
}