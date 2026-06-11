#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  int i = 0;
  bool c = true;
  cin >> a;
  for(i = 0;i < 4;i++){
    if(a[i] == a[i + 1]){
     c = false;
    }
  }
  if(c){
    cout << "Good" << endl;
  }else{
    cout << "Bad" << endl;
}
}