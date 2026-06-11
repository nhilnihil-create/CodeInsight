#include <bits/stdc++.h>
using namespace std;

//最大公約数
long long GCD(long long a, long long b)
{
   if (a%b == 0) {
       return(b);
   }
   else{
       return(GCD(b, a%b));
   }
}

//最小公倍数
long long LCM(long long a, long long b){
   return a * b / GCD(a, b);
}


int main() {
  long long A,B,C,D;
  cin >> A >> B >> C >> D;
  A--;
  long long x = A-((A/C)+(A/D)-(A/LCM(C,D)));
  long long y = B-((B/C)+(B/D)-(B/LCM(C,D)));
  cout << y-x << endl;
}
