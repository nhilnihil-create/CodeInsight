#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for(int i = (s); i < (int)(n); i++)
typedef long long ll;

int main(){
  int n, m, sum=0;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
    sum+=a[i];
  }

  double lim=(double)sum/(4.0*(double)m);
  int cnt=0;
  rep(i, n){
    if(a[i]>=lim){
      cnt++;
    }
    else{
      continue;
    }
  }

  if(cnt>=m){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}