#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k,d,ak,c=0; cin>>n>>k;
  int a[n]={0};
  while(k--){
    cin>>d;
    while(d--) cin>>ak,a[--ak]++;
  }
  for(int i:a) if(!i) c++;
  cout<<c;
}