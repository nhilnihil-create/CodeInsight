#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  long long x = 1000;
  for( int i = 0; i < n-1; i++){
    int w = a.at(i);
      int s = a.at(i +1);
      if(w < s){
        long long t = x/w;
        x %= w;
        x += t*s;
      }
  }
  cout << x << endl;
  
  return 0;
     
}