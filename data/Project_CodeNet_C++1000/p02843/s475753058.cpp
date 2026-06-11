#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x; cin>>x;
  int a=x/100;
  int b=x%100;
  if(a*5<b) cout<<0<<endl;
  else cout<<1<<endl;
}
