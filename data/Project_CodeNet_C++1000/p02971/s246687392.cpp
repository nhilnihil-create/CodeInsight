#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k=0;
  cin >> n;
  int a[n],b[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[i]=a[i];
  }
  sort(b,b+n,greater<int>());
  for(int i=0;i<n;i++){
    if(b[0]==a[i])cout << b[1] << endl;
    else cout << b[0] << endl;
  }
}