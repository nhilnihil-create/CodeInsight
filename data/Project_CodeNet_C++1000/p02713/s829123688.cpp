#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
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

int LCM(int a, int b)
{
   return a * b / gcd(a, b);
}



int main() {
   int K,ans=0;
   cin >> K;
  for(int i=1; i<=K; i++){
   for(int j=1; j<=K; j++){
     for(int k=1; k<=K; k++){
       ans += (GCD (k,(GCD(i,j))));
     }
   }
  }
  cout << ans << endl;
}
