#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<double>u(N+1);
  for(int i=1;i<N+1;i++){
    cin >> u[i];
  }
  sort(u.begin(),u.end());
  double ans;
  for(int i=2;i<N+1;i++){
    if(i==2){
      ans=(u[1]+u[2])/2;
    }
    else{
      ans=(ans+u[i])/2;
    }
  }
  cout << ans << endl;
}