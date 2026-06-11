#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n,c=0; cin>>n;
  for(int i=1;i<=n;i++) if(i%3&&i%5) c+=i;
  cout<<c;
}