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

vector<int> v[30];
signed main(){
  string s,t;
  cin>>s>>t;
  for(int i=0;i<s.length();i++){
    int x=s[i]-'a';
    v[x].pb(i);
    //cout<<x<<endl;
  }
  int cur=-1,ko=0;
  for(int i=0;i<t.length();i++){
    int x=t[i]-'a';
    if(v[x].size()==0){
      cout<<-1<<endl;
      return 0;
    }
    int next=lower_bound(all(v[x]),cur+1)-v[x].begin();
    //cout<<next<<endl;
    if(next==v[x].end()-v[x].begin()){
      ko++;
      cur=v[x][0];
    }
    else cur=v[x][next];
  }
  cout<<ko*s.length()+cur+1<<endl;
  return 0;
}