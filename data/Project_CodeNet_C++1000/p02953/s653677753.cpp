#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  if(n == 1){
    cout << "Yes";
    return 0;
  }
  vector<long long> h(n);
  for(int i = 0; i < n; i++)
    cin >> h.at(i);
  for(int i = 0; i < n -1; i++){
    if(h.at(i) <= h.at(i +1)) continue;
    else if(h.at(i) == h.at(i + 1) + 1){
      h.at(i + 1)++;
      continue;
    }
    else{
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  
}