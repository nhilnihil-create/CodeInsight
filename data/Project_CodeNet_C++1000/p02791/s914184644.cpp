#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<long> p(n);
  for(int i = 0; i < n; i++)
    cin >> p.at(i);
  long minn = p.at(0);
  int ans = 1;
  for(int i = 1; i < n; i++){
    if(minn >= p.at(i)){
      //cout << p.at(i) << endl;
      ans++;
      minn = p.at(i);
    }
  }
  cout << ans << endl;
}
  