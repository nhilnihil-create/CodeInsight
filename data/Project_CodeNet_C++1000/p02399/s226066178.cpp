#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
 
int main()
{
    int  a[] ={0, 0};
    scanf("%d %d", &a[0], &a[1]);
    int d = a[0] / a[1];
    double f = (double)a[0] / a[1];
 
    cout.flags(ios::fixed);
    cout << d <<  " " << a[0] % a[1]  << " " << f << endl;
 
}