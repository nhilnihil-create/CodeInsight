#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int s, w;
  cin >> s >> w;
  
  if(s > w){
    cout << "safe" << endl;
  }
  else if(s <= w){
    cout << "unsafe" << endl;
  }

}