#include <iostream>
#include <math.h>
#include <map>
using namespace std;
int p,q,a,b; double s;
int main() {
    scanf("%d%d",&a,&b);
    p=a/b;
    q=a%b;
    s=(double)a/(double)b;
    printf("%d %d %f\n",p,q,s);
}