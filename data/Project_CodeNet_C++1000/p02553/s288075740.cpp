#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int cnt,i,j,k,a,b,c,d,x,y;
    while(~scanf("%lld %lld %lld %lld",&a,&b,&c,&d))
    {
        x = a*c;
        if(x< a*d) x = a*d;
        if(x< b*c) x = b*c;
        if(x< b*d) x = b*d;
        if(x<0 && ((a<=0 && b>=0) || (c<=0 && d>=0))) x =0;
        cout << x << endl;
    }
    return 0;
}

