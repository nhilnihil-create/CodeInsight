#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    int b=0;
    vector<int> a;
    for(int i=0;i<5;i++){
    cin >> x;
      a.push_back(x);
    }
  for(int k=0;k<5;k++){
      if(a[k]==0){
        b=k+1;
      }
  } 
     cout << b << endl;
    return 0;
}