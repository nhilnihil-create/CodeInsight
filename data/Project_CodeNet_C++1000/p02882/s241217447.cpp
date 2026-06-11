#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
    const double rad=180.0/3.14159265358979323;
    double a,b,wat;
    cin>>a>>b>>wat;
    int air=a*a*b-wat;
    if(air*2.0<=a*a*b)printf("%.10lf\n",atan2(air*2.0/(a*a),a)*rad);
    else printf("%.10lf\n",atan2(b,2.0*wat/(a*b))*rad);
    return 0;
}
