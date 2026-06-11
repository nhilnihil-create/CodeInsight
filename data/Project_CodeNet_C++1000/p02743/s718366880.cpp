#include<bits/stdc++.h>
using namespace std;
const long double EPS = 1e-14;
int main()
{
   long double a,b,k,c=0,x,y;
    cin>>a>>b>>c;
    if(sqrt(a)+sqrt(b)+EPS<sqrt(c))
        cout<<"Yes\n";
    else
        cout<<"No\n";

}
