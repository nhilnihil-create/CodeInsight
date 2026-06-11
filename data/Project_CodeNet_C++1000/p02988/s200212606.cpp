#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  
  vector<int> p(n);
  rep(i,n) cin >> p.at(i);

  int ans = 0;
  rep(i,n){
    if(i==0||i==n-1) continue;
    else if(p.at(i-1)<p.at(i)&&p.at(i)<p.at(i+1)) ans++;
    else if(p.at(i+1)<p.at(i)&&p.at(i)<p.at(i-1)) ans++;
  }

  cout << ans;
}
