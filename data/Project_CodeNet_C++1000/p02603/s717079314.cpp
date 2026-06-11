#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) cin>>a[i];

  int64_t kabu = 0;
  int64_t money = 1000;

  for(int i=0; i<n-1; i++) {
    int64_t add = money/a[i];
    kabu += add;
    money -= add*a[i];

    if(a[i]>a[i+1]) {
      money += a[i]*kabu;
      kabu = 0;
    }
  }

  money += a[n-1]*kabu;
  kabu = 0;


  cout<<money<<endl;

  return 0;
}