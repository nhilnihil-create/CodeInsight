#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,a,b;
  cin >> n >> a >> b;
  int64_t cnt=n/(a+b);
  int64_t caat=n%(a+b);
  if(caat>a)caat=a;
  cout << a*cnt+caat << endl;
}
