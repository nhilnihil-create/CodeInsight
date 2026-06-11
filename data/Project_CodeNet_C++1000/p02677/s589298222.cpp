#include <bits/stdc++.h>
#define PI 3.14159265358979323
typedef long double LD;

using namespace std;

int main(){
    int a,b,h,m;
    cin >> a >> b >> h >> m;

    LD rad = PI*2*((LD)h/12.0 + ((LD)m/60.0) /12.0  - (LD)m/60.0 );
    LD rsq = (LD)(a*a + b*b) - (LD)(2*a*b)* cos(rad);

    printf("%20.20Lf\n",sqrt(rsq));

}