#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;
typedef unsigned long long int ull;
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c,ans;
  string s,t;
  cin >>a>>b>>c;
  if(a>=b&&a>=c)ans=b+c;
  if(b>=a&&b>=c)ans=a+c;
  if(c>=b&&c>=a)ans=b+a;
  cout <<ans;
}