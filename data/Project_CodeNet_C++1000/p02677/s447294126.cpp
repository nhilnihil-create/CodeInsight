/*
Sharif Hasan - CSE, PUST
Apr 24, 2020 02: 14 PM
*/
#include<bits/stdc++.h>
#include "string.h"
#define br cout<<"\n"
#define what(x) cout<<"in here var= "<<x<<"\n";

/*STL definations*/
#define pb push_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FROM(a,i,n) for(int i=a;i<n;i++)
using namespace std;
double clockAngle(double a,double b){
    double f=fabs(b*6-(a*30+b/2));
    if(f>180) f=360-f;
    return  f*acos(-1)/180.0;
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    printf("%.14f\n",sqrt(a*a+b*b-2*a*b*cos(clockAngle(c,d))));
    return 0;
}