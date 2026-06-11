//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll n,b;
    double x;
    cin>>n;
    x=n/1.08;
    b=ceil(x);
    if(floor(b*1.08)==n)
    cout<<b<<endl;
    else cout<<":("<<endl;

    return 0;
}



