#include <bits/stdc++.h>

using namespace std;

int main(){
  string x;
  cin >> x;
  for (int i = 0; i < x.size();i++){
    x[i] = 'x';
  }
  cout << x << endl;

}

//stringにもfor文は使える。