#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    p.at(i) = make_pair(b,a);
  }
  
  sort(p.begin(),p.end());
  
  int total=0;
  for(int i=0;i<n;i++){
    int a,b;
    tie(b,a) = p.at(i);
    total += a;
    if(total > b){
      cout << "No" << endl;
      return(0);
    }
  }
  
  cout << "Yes" << endl;
  
  return(0);
}