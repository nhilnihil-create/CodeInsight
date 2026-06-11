#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    double ans=0.0;
    ans=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    printf("%.8f\n",ans);
    return 0;
}