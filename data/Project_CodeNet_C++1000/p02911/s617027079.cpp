#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t n, k, q;
  cin >> n >> k >> q;
  
  vector<int64_t> a(q);
  for(int i=0; i<q; i++){
    cin >> a[i];
  }
  
  map<int64_t, int64_t> score;
  for(int j=0; j<q; j++){
    score[a[j]]++;
  }
  
  for(int m=1; m<n+1; m++){
    if(score[m]>q-k){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }

  
}