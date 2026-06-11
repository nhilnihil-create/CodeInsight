#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k,q; cin >> n >> k >> q;
  vector<int> player(n,k);
  vector<int> ans(n,0);
  for(int i = 0; i < q; i++){
    int a; cin >> a;
    ans.at(a - 1)++;
  }
  for(int i = 0; i < n; i++){
    player.at(i) += ans.at(i) - q;
    if(player.at(i) > 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  
}
