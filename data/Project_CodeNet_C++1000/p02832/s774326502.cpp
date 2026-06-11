#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k=1;
  cin >> n;
  int a[n];
  bool t=true;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]==k)k++;
    if(a[i]==1)t=false;
  }
  if(t)cout << -1 << endl;
  else cout << n-(k-1) << endl;
}
  