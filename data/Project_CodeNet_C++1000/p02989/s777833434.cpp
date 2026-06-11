#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x, y, z, ans=0;
  cin>>N;
  if(N%2==1) {
    cout<<ans<<endl;
  }
  else {
    x=N/2;
  
  vector<int> n(N);
  for(int i=0; i<N; i++){
    cin>>n.at(i);
  }
  sort(n.begin(), n.end());
  y = n.at(x-1);
  z = n.at(x);
  if(y==z) cout<<ans<<endl;
  else {
    y++;
    while(y<=z){
      ans++;
      y++;
    }
    cout<<ans<<endl;
  }
  }
}