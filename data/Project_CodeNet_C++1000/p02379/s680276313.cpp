#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x,y,j,k,a;
    cin>>x>>y>>j>>k;
    a=sqrt((x-j)*(x-j)+(y-k)*(y-k));
    printf("%.4lf\n",a);
    return 0;
}
