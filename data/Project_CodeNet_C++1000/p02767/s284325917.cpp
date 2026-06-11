#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  vector<int> x(n);
  for(int i=0;i<n;i++){
    cin >> x.at(i);
  }
  
  int ans=2000000;
  for(int i=1;i<=100;i++){
    int cost=0;
    for(int xi:x){
      cost+=(xi-i)*(xi-i);
    }
    ans=min(ans,cost);
  }
  cout << ans;
}