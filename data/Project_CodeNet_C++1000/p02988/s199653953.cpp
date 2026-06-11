#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n; cin >> n;
  int p[n];
  for(int i=0; i<n; i++) cin >> p[i];
  int c=0;
  for(int i=1; i<n-1; i++){
    if(min({p[i-1], p[i], p[i+1]})!=p[i] && max({p[i-1], p[i], p[i+1]})!=p[i]) c++;
  }
  cout << c;
  return 0;
}