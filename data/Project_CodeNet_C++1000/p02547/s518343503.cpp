#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> d1(n),d2(n);
  for(int i=0;i<n;i++){
    cin >> d1.at(i) >> d2.at(i);
  }
  
  int k = -1;
  for(int i=0;i<n-2;i++){
    if(d1.at(i) == d2.at(i)){
      if(d1.at(i+1) == d2.at(i+1)){
        if(d1.at(i+2) == d2.at(i+2)) k = 0;
      }
    }
  }
 
  if(k == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}