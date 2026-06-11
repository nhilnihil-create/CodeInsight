#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a,b;
    cin>>a>>b;
    ll lcm=a*b/__gcd(a,b);
    cout<<lcm<<endl;
    exit(0);
}
