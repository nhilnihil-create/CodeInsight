#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){

    double l;

    cin >> l;

    double a = l / 3;
    double b = (l - a) / 2;
    double c = l - a - b;
    
    printf("%.12f\n", a * b * c);

    return 0;
} 
