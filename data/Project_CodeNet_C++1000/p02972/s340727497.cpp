#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n;
  cin>>n;
  int a[n+1];
  rep(i,0,n) cin>>a[i+1];
  int m=0;
  int b[n+1];
  rep(i,0,n+1) b[i]=0;
  bool ok=true;
  for(int i=n;i>=1;i--){
                int cnt=0;//iの倍数のはこに何個入っているか mod2
                int s=i;
                
    
                while(s+i<=n){
                          s+=(i);
                          if(b[s]==1){
                            cnt+=1;
                            cnt%=2;
                           // cout<<s<<a[i]<<cnt<<endl;
                          }
                }   
               if(a[i]!=cnt){
                           m++;
                           b[i]=1;
               }
  }
  if(ok){
  cout<<m<<endl;
  rep(i,1,n+1){
    if(b[i]==1)
   cout<<i<<" "; 
  }
    cout<<endl;
  }
  else cout<<-1<<endl;
}

