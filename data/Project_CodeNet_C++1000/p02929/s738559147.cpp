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

int sa[200010];
int ko_1=0;
int ko_m1=0;
int kosuu[200010];

int add(int a,int b){
  return (a+b)%MOD;
}
int prod(int a,int b){
  return (a*b)%MOD;
}
int kaijo(int x){
  if(x==0)return 1;
  return prod(x,kaijo(x-1));
}
signed main(){
  int n;
  int ans=1;
  string s;
  cin>>n>>s;
  if(s[0]=='W' || s[2*n-1]=='W'){
    cout<<0<<endl;
    return 0;
  }
  rep(i,2*n){
    if(i==0)sa[0]=1;
    else{
      if(s[i-1]!=s[i])sa[i]=sa[i-1];
      else sa[i]=-sa[i-1];
    }
    //cout<<sa[i]<<endl;
    if(sa[i]==1)ko_1++;
    if(sa[i]==-1){
      ans=prod(ans,ko_1-ko_m1);
      ko_m1++;
    }
  }
  if(ko_1!=n)ans=0;
  ans=prod(ans,kaijo(n)); 
  cout<<ans<<endl;
  return 0;
}