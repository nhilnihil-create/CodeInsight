#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
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

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}


int main(){
  long long A,B,C,D;
  cin>>A>>B>>C>>D;
  
  cout<<(B-A+1)-(B/C-(A-1)/C)-(B/D-(A-1)/D)+(B/lcm(C,D)-(A-1)/lcm(C,D))<<endl;
  
  
}