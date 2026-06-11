#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin>>x;
  int a=x/100;
  int b=x%100;
  if(b>5*a) cout<<0<<endl;
  else cout<<1<<endl;
}
