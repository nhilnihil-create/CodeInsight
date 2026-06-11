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
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
    a[i]--;
  }
  vector<int> cnt(n, -1);
  cnt[0]=0;
  int next=a[0], pre=0;
  while(cnt[next]==-1){
    cnt[next]=cnt[pre]+1;
    pre=next;
    next=a[next];
  }
  ll cycle=cnt[pre]-cnt[next]+1;
  int ans;
  if(k-cnt[next]<0){
    ans=0;
    while(k!=0){
      ans=a[ans];
      k--;
    }
  } else {
    k-=cnt[next];
    k%=cycle;
    ans=next;
    while(k!=0){
      ans=a[ans];
      k--;
    }
  }
  cout << ans+1 << endl;
  return 0;
}
