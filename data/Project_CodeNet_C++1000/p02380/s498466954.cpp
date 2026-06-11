#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, C;

    cin >> a >> b >> C;

    double b_cos = b * cos(C*2*M_PI/360.);
    double b_sin = b * sin(C*2*M_PI/360.);

    double S = a * b_sin / 2;
    double c;
    if(a == b_cos){
        c = b_sin;
    }else{
        c = sqrt((a-b_cos) * (a-b_cos) + b_sin*b_sin);
    }

    printf("%.8f\n", S);
    printf("%.8f\n", (a+b+c));
    printf("%.8f\n", b_sin);
}
