#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  bool ok=true;
  int b;
  for(int i=0;i<n;i++){
    cin >> b;
    if(b%2==0)
      if(b%3!=0&&b%5!=0)
        ok=false;
  }
  cout << (ok?"APPROVED":"DENIED") << endl;
  return 0;
}