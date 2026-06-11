#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e9;
int main()
{
    ll s;
    cin>>s;
    ll x2=N,x3=1,y2,y3;
    y3=s/N+1,y2=y3*N-s;
    if(y2==N)   {y3--;y2=0;}
    cout<<0<<" "<<0<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
}