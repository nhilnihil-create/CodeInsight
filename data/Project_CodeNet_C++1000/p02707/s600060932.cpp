#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n) mp[i] = 0;

  rep(i,n){
    if(i == 0) continue;
    int a;
    cin >> a;
    a--;
    mp[a]++;
  }

  for(auto p:mp) cout << p.second << endl;
  
  
}
