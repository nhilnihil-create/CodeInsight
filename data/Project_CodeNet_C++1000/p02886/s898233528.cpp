#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int>data(n);
  for(int i=0;i<n;i++){
    cin >> data.at(i);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(i!=j) ans+=data.at(i)*data.at(j);
    }
  }
  cout << ans << endl;
}
