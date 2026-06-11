#include<bits/stdc++.h>
using namespace std;
const int N=1e3+15;
typedef long long ll;
int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    if(a<b)
        swap(a,b);
    if((a-b)%2==0)
    {
        cout<<((a-b)/2)<<endl;
    }
    else
    {
        ll d=(a-b)/2;
        ll op1=b;
        ll op2=n-a+1;
        cout<<min(op1,op2)+d<<endl;
    }
    return 0;
}
