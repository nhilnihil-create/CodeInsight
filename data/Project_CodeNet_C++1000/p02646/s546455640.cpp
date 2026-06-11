#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll A,V,B,W,T; cin >> A >> V >> B >> W >> T;
  if((abs(B-A)/T)>V-W){
    cout << "NO" << endl;
    return 0;
  }
  if(abs(B-A)%T!=0 && abs(B-A)/T==V-W){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}