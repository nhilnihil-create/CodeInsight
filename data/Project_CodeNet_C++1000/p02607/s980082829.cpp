#include <bits/stdc++.h>
#define LL               long long
#define PB               push_back
using namespace std;
int main(){
  int n,c=0; cin>> n;
  int a[n+1];
  for (int i=1;i<=n;i++){
    cin >> a[i];
  }
  for (int i=1;i<=n;i++){
    if ((i%2) && (a[i]%2)) c++ ;
  }
  cout<< c<<endl;
}