#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int a,b,c,d;
  cin >> a >> b >> c >> d;
  long long int p = a*c;
  long long int q = a*d;
  long long int r = c*b;
  long long int s = b*d;
  cout << max(p,max(q,max(r,s)));
}