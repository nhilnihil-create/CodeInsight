#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  if (a >= c || b >= c){
    cout << "No";
  }
  else if ((c - a - b) * (c - a - b) - 4 * a * b > 0){
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}
  