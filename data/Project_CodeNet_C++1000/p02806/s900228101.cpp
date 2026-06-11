#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<pair<string,int>> s(N);
  REP(i,N){
    cin>>s[i].first>>s[i].second;
  }
  string x;cin>>x;
  int ans=0;
  bool f=false;
  for(int i=0;i<N;i++){
    if(f)ans+=s[i].second;
    if(!f&&s[i].first==x)f=true;
  }
  cout<<ans<<endl;
  
  
  


  return 0;
}
