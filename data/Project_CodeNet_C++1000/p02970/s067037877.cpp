#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d;
  cin >> n>>d;
  int x=n/(d*2+1);
  if(n%(d*2+1)!=0){
    cout<<x+1;
  }
  else{
    cout<<x;
  }
}
