#include <bits/stdc++.h>
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
using namespace std;

long long gcd(long long, long long);
long long lcm(long long, long long );

int main(){
  long long a,b;
  cin >> a >> b;
  
  cout << lcm(a,b) << endl;
}

long long gcd(long long a, long long b)
{
   if (a%b == 0){
     return(b);
   }else{
     return(gcd(b, a%b));
   }
}

long long lcm(long long a, long long b)
{
   return a * b / gcd(a, b);
}