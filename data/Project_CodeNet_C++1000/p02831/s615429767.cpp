#include<bits/stdc++.h>
using namespace std;
long long n,i,a,b;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

int main()
{
    cin>>a>>b;
    if(gcd(a,b)==1)
        cout<<a*b<<endl;
    else
    cout<<lcm(a,b);
}
