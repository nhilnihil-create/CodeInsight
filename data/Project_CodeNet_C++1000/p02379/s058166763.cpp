#include "bits/stdc++.h"
using namespace std;
int main(){
    double a,b,c,d,r;
    cin >> a >> b >> c >> d;
    r = (a-c)*(a-c)+(b-d)*(b-d);
    printf("%.4lf\n",sqrt(r));
    return 0;
}
