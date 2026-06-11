#include<bits/stdc++.h>
using namespace std;

int main()
{
    double L,ans=1;
    cin>>L;
    L=L/3.0;
    ans*=L;
    ans*=L;
    ans*=L;
    printf("%.12lf\n",ans);
    return 0;
}
