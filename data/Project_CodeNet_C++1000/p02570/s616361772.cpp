#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, t, v;
  cin >> l >> t >> v;
  int vt= t*v;
  if(l<=vt){
    cout << "Yes" << endl;
  }
  else{
    cout << "No"<<endl;
  }
}