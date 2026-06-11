#include <bits/stdc++.h>
using namespace std;
int main(){
  int d, t, s;
  float time;
  cin >> d >> t >> s;
  time = (float)d/(float)s;
  if (time <= t){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}