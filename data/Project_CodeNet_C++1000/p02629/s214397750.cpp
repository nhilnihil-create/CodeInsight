#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

1-26 = a-z
27 = aa

26進数
でも0がない感じ

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N; cin >> N;
  string word = "zabcdefghijklmnopqrstuvwxy";
  string ans;
  N--;
  while (1){
    char c = N%26 + 'a';
    ans += c;
    N /= 26;
    N--;
    if (N < 0)
      break;
  }
  ll end = ans.size();
  while(--end >= 0)
    cout << ans[end];    
  cout << endl;
}
