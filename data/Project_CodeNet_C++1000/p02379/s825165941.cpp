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
double di(double a,double b,double c,double d){return sqrt((c-a)*(c-a)+(d-b)*(d-b));}

int main(){
    double pai=3.141592653589;
    double x1,y1,x2,y2,ans;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    printf("%lf\n",di(x1,y1,x2,y2));
    return 0;
}