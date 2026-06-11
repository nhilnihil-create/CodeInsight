#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n, k; cin >> n >> k;
  vector<int> sunuke(n);
  int okashi=0, d=0; 
  
  for (int i=0; i<k; i++){
    cin >> d;
    for (int j=0; j<d; j++){
      cin >> okashi;
      sunuke.at(okashi-1)++;
    }
  }
  int cnt =0;
  for (int i=0; i<n; i++){
    if (sunuke.at(i)==0){
      cnt++;
    }
  }
  cout << cnt << endl;
}