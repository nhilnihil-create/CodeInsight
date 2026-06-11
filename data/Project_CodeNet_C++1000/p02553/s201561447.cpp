#include<iostream>
#include<cmath>
#include<algorithm>
#include<array>
#include<cstdio>
#include<functional>
using namespace std;
int main()
{
    long long int a,b,c,d,product;
    cin>>a>>b>>c>>d;
    array<long long int,4>m;
    m[0] = a*c;
    m[1] = a*d;
    m[2] = b*c;
    m[3] = b*d;

    sort(m.begin(),m.end());
    product = m.at(3);
    cout<<product<<'\n';
    return 0;
}
