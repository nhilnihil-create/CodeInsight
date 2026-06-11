#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


long long gcd(long long a, long long b) {
   if (a%b == 0) {
       return(b);
   }
   else {
       return(gcd(b, a%b));
   }
}

long long lcm(long long a, long long b) {
   long long tmp = max(a,b)/gcd(a,b);
   return min(a,b)*tmp;}

int main() {
   long long a, b;
   cin >> a >> b;

   cout << lcm(a, b) << endl;
   return 0;
}