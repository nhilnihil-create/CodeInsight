#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  bool flag=false;
  if(n%2!=0){
    vector<int> v(n);
    v.at(0) = 7%n;
    for(int i=1; i<n; i++)
      v.at(i) = (v.at(i-1)*10 + 7) % n;
    
    for(int i=0; i<n; i++)
      if(v.at(i)==0){
        cout << i+1 << endl;
        flag=true;
        break;
      }
  }
  if(!flag)
    cout << "-1" << endl;
}
