#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> d(1000005);
  vector<bool> visited(1000005);
  rep(i, n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  rep(i, n){
    int x=a[i];
    if(visited[x])continue;
    visited[x]=true;
    while(x+a[i]<=1000000){
      x+=a[i];
      d[x]=true;
    }
  }
  int ans=0;
  rep(i, n){
    if(!d[a[i]]){
      if(i!=0 && a[i]==a[i-1])continue;
      if(i!=n-1 && a[i+1]==a[i])continue;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
