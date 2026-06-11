#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  if(n!=1)
    cout << floor(log10(n)/log10(k))+1 << endl;
  else
    cout << 1 << endl;
  return 0;
}