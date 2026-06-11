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
  int ans=1;
  for(int i=1;i<len(s);i++){
    if(s[i]==s[i-1]&&i==len(s)-1){
      continue;
    }
    if(s[i]==s[i-1]&&i==len(s)-2){
      ans++;
      break;
    }
    if(s[i]==s[i-1]&&i!=len(s)-1){
      i+=2;
      ans+=2;
      continue;
    }
    ans++;
  }
  cout<<ans<<endl;
}