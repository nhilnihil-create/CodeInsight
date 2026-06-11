#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n),b(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(),b.end());
  int max_value = b[b.size()-1];
  int sec_value = b[b.size()-2];
  for(int i=0; i<n; i++) {
    if(max_value==sec_value){
      cout << max_value << endl;    
    } else if(a[i]==max_value) {
      cout << sec_value << endl;    
    } else {
      cout << max_value << endl;     
    }
  }
  return 0;
}