#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main(){
  string s;
  cin>>s;
  vector<int> a(len(s)+1,0);
  rep(i,len(s)){
    if(s[i]=='<'){
      a[i+1]=a[i]+1;
    }
  }
  for(int i=len(s)-1;i>=0;i--){
    if(s[i]=='>'){
      a[i]=max(a[i+1]+1,a[i]);
    }
  }
  ll ans=0;
  rep(i,len(s)+1){
    ans+=a[i];
  }
  cout<<ans<<endl;
}
