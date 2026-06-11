#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, sum = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i=0 ; i<n ; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  int pop = 0;
  float basis = sum*0.25/m;
  
  for (int i=0 ; i<n ; i++){
    if (a.at(i) >= basis)
      pop++;
  }
  
  if (pop >= m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}