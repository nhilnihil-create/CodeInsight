#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repp(i, n) for(int i = 1; i <= (int)(n); i++)
#define co(x) cout<<x<<endl
typedef long long int lint;
 
int main() {
  long double a,b,c;
  cin >> a >> b >> c;
  if(a + 2*sqrt(a*b) + b < c){co("Yes");}
  else{co("No");}
}