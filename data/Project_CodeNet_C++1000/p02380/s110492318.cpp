#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * vector<int>ar(3);
 * for(auto&e:ar){
 *     scanf("%d",&e);
 * }
 * sort(ar.begin(),ar.end())
 * int sum=accumulate(ar.begin(),ar.end(),0);
 ***/

int main(){
    double pai=3.141592653589;
    int a,b,C;
    double S,L,h,rad,cs;
    scanf("%d %d %d",&a,&b,&C);
    rad=C*pai/180;
    cs=sqrt(a*a+b*b-2*a*b*cos(rad));
    h=b*sin(rad);
    printf("%.8lf\n%.8lf\n%.8lf\n",h*a/2,a+b+cs,h);
    return 0;
}