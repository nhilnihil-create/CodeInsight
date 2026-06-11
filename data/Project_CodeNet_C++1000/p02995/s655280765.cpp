#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
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

long long int lcm(long long int a, long long int b)
{
   return a * b / gcd(a, b);
}

int main(){
    
    long long int a,b;
    cin >> a >> b;
    long long int c,d;
    cin >> c >> d;
    long long int e=lcm(c,d);

    cout << (b-a+1)-(b/c-(a-1)/c+b/d-(a-1)/d-b/e+(a-1)/e) << endl;

}