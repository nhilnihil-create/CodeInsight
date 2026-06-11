#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> lig(n);
  for(int i=0; i<n; ++i) cin >> lig[i];
  for(int i=0; i<k; ++i){
    vector<int> nlig(n+1,0);
    for(int j=0; j<n; ++j){
      int plus = max(0,j-lig[j]);
      int mai = min(n,j+lig[j]+1);
      ++nlig[plus];
      --nlig[mai];
    }
    for(int j=1; j<n; ++j) nlig[j] += nlig[j-1];
    if(lig == nlig) break;
    lig = nlig;
  }
  for(int i=0; i<n; ++i){
    if(i == n-1) cout << lig[i] << endl;
    else cout << lig[i] << " ";
  }
}