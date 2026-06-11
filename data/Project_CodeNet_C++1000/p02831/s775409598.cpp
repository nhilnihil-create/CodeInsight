#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long int a,b,x;
     cin>>a>>b;
     x=__gcd(a,b);
     x=(a*b)/x;
     cout<<x;
}
