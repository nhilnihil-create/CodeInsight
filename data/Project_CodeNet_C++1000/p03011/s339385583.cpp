#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int x1=d1+d2;
    int x2=d1+d3;
    int x3=d2+d3;
    int menor=0;
    menor=min({x1,x2,x3});
    cout << menor;
    return 0;
}