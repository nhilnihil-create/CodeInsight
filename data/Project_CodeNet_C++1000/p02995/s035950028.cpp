#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0){return(b);}else{return(gcd(b, a%b));}
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}

int main(){
  
  long long i, A, B, C, D, Ca, Da, CD, CDa;
  cin >> A >> B >> C >> D;
  
  Ca = B/C - (A/C + 1 - (A%C==0)) + 1;
  Da = B/D - (A/D + 1 - (A%D==0)) + 1;
  CD = lcm(C, D);
  CDa = B/CD - (A/CD + 1 - (A%CD==0)) + 1;
  
  cout << B - A + 1 - (Ca + Da - CDa) << endl;
  return 0;
}