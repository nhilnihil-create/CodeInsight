#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  vector<int> a(n);
  double vote = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    vote += a.at(i);
  }
  vote = vote /(4 * m);
  
  for(int i = 0; i < n; i++){
    if(a.at(i) >= vote){
      cnt++;
      if(cnt == m){
    	cout << "Yes";
        return 0;
      }
    }
  }
    cout << "No";
}
