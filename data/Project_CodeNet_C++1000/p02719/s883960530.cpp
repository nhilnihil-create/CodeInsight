#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,k;
  cin>>n>>k;
  long long amari=n%k;
  long long kotae=min(amari,abs(k-amari));
  cout<<kotae<<endl;
  return 0;
}