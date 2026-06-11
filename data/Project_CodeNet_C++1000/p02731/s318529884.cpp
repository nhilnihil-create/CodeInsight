#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    double l;
    cin >> l;

    // arithmetic-geometric mean 
    // (a*b*c)^(3/1) <= (abc)/3

    printf("%.12f\n",(double) l*l*l/27);
    
    return 0;
}