#include<bits/stdc++.h>
using namespace std;

int main(){
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  
  if(h2 == 0) h2 += 24;
  
  cout << (h2 * 60 + m2) - (h1 * 60 + m1) - k << endl;
}