#include <bits/stdc++.h>
using namespace std;

#define	rep(i,n)	for(int i=0;i<n;i++)

bool check(long long x){
  int n=sqrt(x);
  bool ok=true;
  for(int i=2;i<n;i++){
    if(x%i==0)	ok=false;
  }
  return ok;
}

int main() {
  long long x;	cin >> x;
  while(1){
    if(check(x))	break;
    x++;
  }
  cout << x;
}
