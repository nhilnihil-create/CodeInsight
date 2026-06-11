#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

int main() {
  int k;
  int sum = 0;

  cin >> k;

  int tmp;

  int a=1;
  int b=1;
  int c=1;


  // k++;

  for(int i=1; i<=k; i++){
      for(int j=1; j<=k; j++){
          for(int l=1; l<=k; l++){
            tmp = gcd(i,j);
            sum += gcd(tmp,l);
          }
      }
  }


  cout << sum;


}