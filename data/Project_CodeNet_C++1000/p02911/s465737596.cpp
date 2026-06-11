#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(q);
  for(int k = 0; k < q; k++){
    cin >> a.at(k);
  }	//input
  
  for(int j = 0; j < q; j++){
    a.at(j)--;
  }
  
  vector<int> point(n, -q);
  for(int i = 0; i < q; i++){
    point.at(a.at(i))++;
  }
  
  for(int i = 0; i < n; i++){
    if(point.at(i) > -k) cout << "Yes" << endl;
    else cout <<"No" << endl;
  }
}