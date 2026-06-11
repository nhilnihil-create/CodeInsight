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

int Time[100];
map<string,int> ma;
signed main(){
  int n;cin>>n;
  rep(i,n){
    string s;
    int t;
    cin>>s>>t;
    ma[s]=i;
    Time[i]=t;
  }
  string x;cin>>x;
  int ans=0;
  for(int i=ma[x]+1;i<n;i++)ans+=Time[i];
  cout<<ans<<endl;
  return 0;
}
