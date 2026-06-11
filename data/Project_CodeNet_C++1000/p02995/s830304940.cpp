#include <bits/stdc++.h>
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
  long long A,B,C,D;
  cin >> A >> B >> C >> D;
  long long E=lcm(C,D);
  long long ans=(B-A+1)-((B/C)-(A/C))-((B/D)-(A/D))+((B/E)-(A/E));
  if(A%C==0){
    ans--;
  }
  if(A%D==0){
    ans--;
  }
  if(A%E==0){
    ans++;
  }
  cout << ans << endl;
}