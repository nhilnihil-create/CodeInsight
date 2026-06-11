#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,k;
  cin >> a >> b >> k;
  long long n=max(0ll,a-k);
  long long m=min(b,max(a+b-k,0ll));
  cout << n << " " << m << endl;
  return 0;
}