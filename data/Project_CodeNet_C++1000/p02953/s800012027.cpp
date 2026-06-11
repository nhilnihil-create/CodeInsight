#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin >> h.at(i);
  }
  
  if(n==1){
    cout << "Yes" << endl;
    return(0);
  }
  
  for(int i=h.size()-1;i>=1;i--){
    if(h.at(i-1)-1 > h.at(i)){
      cout << "No" << endl;
      return(0);
    }else if(h.at(i-1)-1 == h.at(i)){
      h.at(i-1)--;
    }
  }
  
  cout << "Yes" << endl;
  
  return(0);
}