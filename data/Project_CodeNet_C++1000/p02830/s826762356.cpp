#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  string s, t;
  cin >> n >> s >> t;
  
  for (int i=0 ; i<n ; i++)
    cout << s.at(i) << t.at(i);
}