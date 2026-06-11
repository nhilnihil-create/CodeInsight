#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define SZ(x) ((int)(x).size())
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const double pi=acos(-1);


 
int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  if (c>a+b && 4*a*b<(a+b-c)*(a+b-c)) puts("Yes");
  else puts("No");
}
