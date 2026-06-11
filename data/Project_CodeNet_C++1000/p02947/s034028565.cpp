#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll ans=0;
  map<string,int> ma;
  rep(i,n){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    ans+=ma[s];
    ma[s]++;
  }
  cout << ans << endl;
  
}