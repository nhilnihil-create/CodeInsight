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

int main(void){
    long long int A,B;
    cin >> A >> B;
    cout << lcm(A,B);
}