#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  cin >> a;
  int now;
  cin >> now;
  long long sum = 0;
  for (int i=1;i<a;i++){
    int b;
    cin >> b;
    if (now > b){
      sum += now - b;
    } else now = b;
  }
  cout << sum << endl;
}