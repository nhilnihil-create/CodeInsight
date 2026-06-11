#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;
map<string,int> ma;
signed main(){
  int n;cin>>n;
  rep(ima,n){
    string s;cin>>s;
    int m=s.length();
    rep(i,m){
      for(int j=i+1;j<m;j++){
        if(s[i]>s[j])swap(s[i],s[j]);
      }
    }
    ma[s]++;
  }
  int ans=0;
  for(auto p:ma){
    int po=p.S;
    ans+=po*(po-1)/2;
  }
  cout<<ans<<endl;
  return 0;
}
