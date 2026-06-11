#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int main()
{
    long long a,b,h,m;
  long double mi, ho,rad, distance;
    cin>>a>>b>>h>>m;
    mi = m/60.0;
    ho = m/720.00 + h/12.00;
    rad = 2*3.14159265358979323846*(mi-ho);
    distance = sqrt(a*a + b*b - 2 *a*b*cos(rad));
    cout<<fixed<<setprecision(20)<<distance;
}
