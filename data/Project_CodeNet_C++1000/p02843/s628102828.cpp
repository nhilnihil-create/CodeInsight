#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int x;
  cin>>x;
  if(x>=2000)
    cout << 1 << endl;
  else if((x/100)*5>=x%100)
    cout << 1 << endl;
  else cout << 0 << endl;
}