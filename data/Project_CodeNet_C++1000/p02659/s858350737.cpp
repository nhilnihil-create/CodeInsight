#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int a,b,c;
  cin >> a;
  scanf("%lld.%lld",&b,&c);
  b = b*100+c;
  long long int ans = (a*b)/100;
  cout << ans << endl;
}