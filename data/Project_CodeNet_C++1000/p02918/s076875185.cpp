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

signed main(){
  int n,k;cin>>n>>k;
  string s;cin>>s;
  int one=0,two=0;
  rep(i,n+1){
    if(i==0){
      if(s[0]=='L')one++;
    }
    else if(i==n){
      if(s[n-1]=='R')one++;
    }
    else if(s[i-1]=='R' && s[i]=='L')two++;
  }
  while(k>0 && one+2*two>2){
    if(two>0)two--;
    else if(one>0)one--;
    k--;
  }
  if(k>0 && (one+2*two)<=2)one=1,two=0;
  cout<<n-(one+2*two)<<endl;
  return 0;
}