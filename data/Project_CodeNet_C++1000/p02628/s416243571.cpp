#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> p;
  rep(i,n){
    int tmp;
    cin >> tmp;
    p.push_back(tmp);
  }
  sort(p.begin(),p.end());
  long ans = 0;
  rep(i,k)ans += p[i];
  cout << ans << endl;
  return 0;
}