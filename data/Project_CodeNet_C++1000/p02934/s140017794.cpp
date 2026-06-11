#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  double b=0;
  for(int i=0;i<n;i++){
    b+=1.0/a[i];
  }
  cout<<1/b<<endl;
}