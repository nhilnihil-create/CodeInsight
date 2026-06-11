#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  int b = a.size();
  int count = 0;
  for(int i = 0;i<b/2;i++){
    if(a.at(i)!=a.at(a.size()-i-1))count++;
  }
  cout << count << endl;
}
