#include <bits/stdc++.h>
using namespace std;

int main(){
  int d, t, s;
  cin >> d >> t >> s;
  
  int run = t * s;
  
  if (d <= run){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}