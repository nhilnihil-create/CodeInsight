#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n,a,b;
    cin>>n>>a>>b;
    ll d,x;
    d=(b-a);
    if(d%2==0)
        cout<<d/2<<endl;
    else 
    {
        x=min(min(a-1,n-a),min(b-1,n-b));
        x+=(b-a)/2+1;
        cout<<x<<endl;
    }
    return 0;
}
