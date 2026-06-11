#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s,t;
  cin >> s >> t;

  int ans = 0;
  rep(i,3){
    if(s.at(i)==t.at(i)) ans++;
  }

  cout << ans;

  
}