#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int h, n, sum = 0;
  cin >> h >> n;
  vector<int> a(n);
  for (int i=0 ; i<n ; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  if (sum >= h)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}