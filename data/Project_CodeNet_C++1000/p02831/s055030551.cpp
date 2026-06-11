#include<bits/stdc++.h>
using  namespace  std;

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define nl      '\n'

typedef long long int ll;
typedef unsigned long long int  llu;

long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);

}

 long long int lcm(long long int a,long long int b)
 {
    return (a*b)/gcd(a, b);
 }

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
    return 0;
}
