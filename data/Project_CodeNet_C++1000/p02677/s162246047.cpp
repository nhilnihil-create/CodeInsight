#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    double a,b,h,m;
    cin>>a>>b>>h>>m;
    h = h * 30.0 + m * 0.5;
    m = m * 6.0;

    double sa;
    if(h < m){
        sa = m- h;
    }
    else{
        sa = h - m;
    }
    if(sa > 180.0){
        sa = 360.0 - sa;
    }
    double kaku = (double)sa * M_PI/ 180.0;
    double aa = (double)a;
    double bb = (double)b;
    //cout<<"aa = "<<aa<<", bb = "<<bb<<endl;
    //cout<<"cos = " << cos(kaku)<<endl;
    //cout<<"kaku = "<<kaku<<endl;
    //cout<<"sa = "<<sa<<endl;

    double ans = aa*aa + bb*bb - 2.0 * aa * bb * cos(kaku);
    ans = sqrt(ans);

    printf("%.10lf\n",ans);

    return 0;
}