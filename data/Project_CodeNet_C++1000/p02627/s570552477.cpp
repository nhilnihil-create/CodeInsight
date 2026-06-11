#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  char s; cin >>s;
  char ans='a';
  if (isupper(s)) ans='A';
  cout <<ans <<endl;
  return 0;
}
