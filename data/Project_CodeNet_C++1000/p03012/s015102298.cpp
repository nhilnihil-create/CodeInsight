#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i=0 ; i<n ; i++)
    cin >> w.at(i);
  
  vector<int> s1(n-1);
  vector<int> s2(n-1);
  for (int i=0 ; i<n-1 ; i++){
    s1.at(i) = 0;
    s2.at(i) = 0;
    for (int j=0 ; j<=i ; j++)
      s1.at(i) += w.at(j);
    for (int j=i+1 ; j<n ; j++)
      s2.at(i) += w.at(j);
  }
  
  vector<int> s(n-1);
  for (int i=0 ; i<n-1 ; i++){
    s.at(i) = abs(s1.at(i) - s2.at(i));
  }
  
  sort(s.begin(), s.end());
  
  cout << s.at(0) << endl;
}