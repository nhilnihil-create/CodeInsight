#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  auto max_itr = max_element(a.begin(),a.end());
  int max_index = distance(a.begin(), max_itr);
  int max_value = a[max_index];
  int max2_value;
  if(max_index==0) {
    max2_value = *max_element(max_itr+1, a.end());
  } else if(max_index==a.size()){
    max2_value = *max_element(a.begin(), max_itr-1);  
  } else {
    max2_value = max(*max_element(a.begin(),max_itr-1),*max_element(max_itr+1, a.end()));
  }
  for(int i=0; i<n; i++){
    cout << ( i==max_index ? max2_value : max_value ) << endl;
  }
  return 0;
}