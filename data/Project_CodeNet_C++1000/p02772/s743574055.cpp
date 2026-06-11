#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  
    for(int i = 0; i < n; i++){
      if(a.at(i)%2==1){
        if(i==n-1){
          cout << "APPROVED" << endl;
        }
      }
      else if(a.at(i)%2==0){
      if(a.at(i)%3==0 || a.at(i)%5==0){
        if(i==n-1){
          cout << "APPROVED" << endl;
        }
      }
      else{
        cout << "DENIED" << endl;
        break;
      }
    }
  }    
}