#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a.at(i);

  int maxi;
  int maxcount = 0;
  int nextmax = 0;

  rep(i,n) maxi = max(maxi, a.at(i));
  rep(i,n) if(a.at(i)==maxi) maxcount++;
  rep(i,n){
    if(a.at(i)==maxi) continue;
    nextmax = max(nextmax, a.at(i));
  }

  if(maxcount>=2){
    rep(i,n) cout << maxi << endl;
    return 0;
  }

  rep(i,n){
    if(a.at(i)==maxi) cout << nextmax << endl;
    else cout << maxi << endl;
  }
}
