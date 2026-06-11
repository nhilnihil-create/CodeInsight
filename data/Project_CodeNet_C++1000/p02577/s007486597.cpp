#include <iostream>
using namespace std;
int main(){
  string n;
  cin >> n;
  long long x=0;
  int i;
  for(i=0;i<n.size();i++){
    int a = n[i] - '0';
    x += a;
  }
  if(x%9==0) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}