#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(q);
  for(int i = 0; i < q; i++){
    cin >> a.at(i);
  }	//input
  
  for(int i = 0; i < q; i++){
    a.at(i)--;
  }	//0-index
  
  vector<int> imos(n, 0);
  for(int i = 0; i < q; i++){
    imos.at(0)--;
    imos.at(a.at(i))++;
    if(a.at(i)+1 < n) imos.at(a.at(i)+1)--;
  }		
  for(int i = 1; i < n; i++){
     imos.at(i) += imos.at(i-1);
     //cout << imos[i] << endl;
  }	//imos method
  
  for(int i = 0; i < n; i ++){
    if(imos.at(i) <= -k){
      cout << "No" << endl;
    }
    else{
      cout << "Yes" << endl;
    }
  }

}
  
  
  