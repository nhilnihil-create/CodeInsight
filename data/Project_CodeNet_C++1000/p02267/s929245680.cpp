#include <iostream>
#include <set>
using namespace std;
int main(){
  int n,m,q;
  cin >> n;
  set<int> S;
  for(int i = 0 ; i < n ;i++){
    cin >> m;
    S.insert(m);
  }
  cin >> q;
  int ans=0;
  for(int i = 0; i< q ;++i){
    cin >> m;
    if(S.count(m)==1) ans++;

  }
  cout << ans << endl;

}