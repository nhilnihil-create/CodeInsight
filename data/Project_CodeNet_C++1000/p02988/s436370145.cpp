#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>kazu(n);
  for(int i=0;i<n;i++)
    cin >> kazu.at(i);
  int ans=0;
  for(int i=0;i<n-2;i++){
    if((kazu.at(i)>kazu.at(i+1)&&kazu.at(i+2)<kazu.at(i+1))||(kazu.at(i)<kazu.at(i+1)&&kazu.at(i+2)>kazu.at(i+1)))
      ans++;
  }
  cout << ans << endl;
  return 0;
}