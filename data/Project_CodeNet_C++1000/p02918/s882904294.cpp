#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  s+='.';
  int len=1;
  int st=0;
  int ans = 0;
  priority_queue<int>q;
  rep(i,n){
    if(s[i]==s[i+1])len++;
    else{
      ans += len-1;
      q.push(len);
      len=1;
    }
  }
  while(k){
    k--;
    ans+=2;
    q.pop();
  }
  cout << min(ans,n-1) << endl;
      
      
  return 0;
}