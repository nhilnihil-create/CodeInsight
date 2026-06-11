#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  int s=0;
  cin >> n;
  vector<int> a(n), b(n), c(n-1);
  for(int i=0;i<(n);i++){
    cin >> a.at(i);
  }
  for(int i=0;i<(n);i++){
    cin >> b.at(i);
  }
  for(int i=0;i<(n-1);i++){
    cin >> c.at(i);
  }
  s += accumulate(b.begin(), b.end(), 0);
  for(int i=0;i<(n-1);i++){
    if(a.at(i) == a.at(i+1)-1) s += c.at(a.at(i)-1);
  }
  cout << s << endl;
}