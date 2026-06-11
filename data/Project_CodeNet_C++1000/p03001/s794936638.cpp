#include<bits/stdc++.h>
using namespace std;
#define first ff
#define second ss
#define ll long long int
int main()
{
    ll w,h,x,y;
    cin>>w>>h>>x>>y;
    int c=0;

    if(2*x==w && 2*y==h) c=1;

    double mx=(w*h)/2.0;
    printf("%.6lf %d",mx,c);

}
