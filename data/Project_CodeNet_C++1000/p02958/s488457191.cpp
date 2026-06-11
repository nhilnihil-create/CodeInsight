#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n, a = 0;
  cin >> n;
  vector<int> p(n);
  for (int i=0 ; i<n ; i++){
    cin >> p.at(i);
    if (p.at(i) != i+1)
      a++;
  }
  
  if (a > 2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}