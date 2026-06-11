#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N;
  cin>>N;
  int cnt(0),maxi(0);
  for(int i(0);i<N;i++){
    int a,b;
    cin>>a>>b;
    if(a == b) {
      cnt++;
      maxi = max(maxi, cnt);
    }else{
      cnt = 0;
    }
  }
  if(maxi >= 3) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

