#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int a,flag=0;
  string b;
  cin >> a >> b;
  if(a%2==1) {
    cout << "No";
    return 0;
  }
  for(int i = 0;i<a/2;i++){
    if(b.at(i)!=b.at(i+a/2))flag=1;
  }
  if(flag) cout << "No";
  else cout << "Yes";
}
