#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int gcd(int a, int b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b){
   return a * b / gcd(a, b);
}


int main() {
  ll a,b ;
  cin >> a >> b;
  ll g = lcm(a,b);
  cout << g << endl;
  return 0;

}
