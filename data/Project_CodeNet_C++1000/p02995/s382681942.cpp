#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

long long lcm(long long a, long long b)
{
   return a * b / gcd(a, b);
}

int main(){
    long long a,b,c,d,ans=0,llccmm=0;
    cin >> a >> b >> c >> d;
    ans=b-a+1;
    ans-=b/c;
    ans+=(a-1)/c;
    ans-=b/d;
    ans+=(a-1)/d;
    llccmm=lcm(c,d);
    ans+=b/llccmm;
    ans-=(a-1)/llccmm;
    cout << ans << endl;
    return 0;
}