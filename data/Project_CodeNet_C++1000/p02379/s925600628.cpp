#include <bits/stdc++.h>
using namespace std;

int main() {
    // insert code here...
    double a,b,c,d,oc,od;
    double answer,number1,number2;
    cin>>a>>b>>c>>d;

    number1=double (fabs(d-b));
    number2=double (fabs(c-a));
    answer=double (sqrt(number1*number1+number2*number2));
    
    printf("%lf\n",answer);
    return 0;
}



