#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a,b,k; cin>>a>>b>>k;
  a-=k; if(a<0) b+=a;
  cout<<(a<0?0:a)<<" "<<(b<0?0:b);
}