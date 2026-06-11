#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n,a,b;
  cin >> n >> a >> b;
  
  int64_t shou =  n / (a + b);
  int64_t amari = n % (a + b);
  
  int64_t aamari = 0;
  if(a <= amari){
    aamari = a;
  }else{
    aamari = amari;
  }
  
  int64_t ans = shou * a + aamari;
  cout << ans << endl;
}