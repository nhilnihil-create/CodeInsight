#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  if(islower(b.at(b.size() - 1)) && a == b.erase(b.size()-1)){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
}