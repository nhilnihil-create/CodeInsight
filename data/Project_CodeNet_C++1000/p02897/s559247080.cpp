#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;
typedef unsigned long long int ull;
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c;
  double d;
  string s,t;
  cin >>a;
  b=a/2;
  if(a%2!=0)b++;
  cout <<(double)b/a;
}