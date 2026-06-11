#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(q);
  for(int i = 0; i < q; i++){
    cin >> a[i];
  }	//input
  
  for(int i = 0; i < q; i++){
    a[i]--;
  }	//0-index
  
  vector<int> imos(n, 0);
  for(int i = 0; i < q; i++){
    imos[0]--;
    imos[a[i]]++;
    if(a[i]+1 < n) imos[a[i]+1]--;
  }		
  for(int i = 1; i < n; i++){
     imos[i] += imos[i-1];
     //cout << imos[i] << endl;
  }	//imos method
  
  for(int i = 0; i < n; i ++){
    if(imos[i] <= -k){
      cout << "No" << endl;
    }
    else{
      cout << "Yes" << endl;
    }
  }
}
  
  
  