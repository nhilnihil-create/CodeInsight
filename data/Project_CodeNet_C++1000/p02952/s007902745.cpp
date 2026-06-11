#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a=0; cin>>n;
  cout<<(n<10?n:n<100?9:n<1000?n-90:n<10000?909:n<100000?n-9090:90909);
}