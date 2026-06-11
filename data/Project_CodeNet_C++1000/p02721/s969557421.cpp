#include<bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
// using namespace atcoder;

const ll mod=1000000007;//998244353;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n,k,c;
  cin >> n >> k >> c;

  string s;
  cin >> s;
  vec a(n);//i日目以降、できるだけ頑張って働いたときの最大日数
  vec b(n);//i日目からさかのぼって、できるだけ頑張って働いたときの最大日数

  vec d;//働ける日を記録
  for(ll i=0;i<n;i++)if(s[i]=='o')d.emplace_back(i);

  for(ll i=n-1;i>=0;i--){
    if(i+c+1>=n){
      if(s[i]=='o')a[i]=1;
      else if(i<d[d.size()-1])a[i]=1;
    }
    else{
      if(s[i]=='o')a[i]=a[i+c+1]+1;
      else if(i!=n-1)a[i]=a[i+1];
    }
  }

  for(ll i=0;i<n;i++){
    if(i<c+1){
      if(s[i]=='o')b[i]=1;
      else if(d[0]<i)b[i]=1;
    }
    else{
      if(s[i]=='o')b[i]=b[i-c-1]+1;
      else if(i!=0)b[i]=b[i-1];
    }
  }

  vec e;//愚直に働いた場合、どこで働くか
  ll t=mod;
  for(ll i=0;i<n;i++){
    if(s[i]=='x'){
      t++;
      continue;
    }
    else{
      if(t<c)t++;
      else{
        e.emplace_back(i);
        t=0;
      }
    }
  }

  //for(ll i=0;i<3;i++)cout << e[i] << endl;

  vec ans;
  for(ll i=0;i<n;i++){
    if(s[i]=='x')continue;
    if(i<=e[0]){
      if(i!=(n-1)){
        if(a[i+1]<k)ans.emplace_back(i+1);
      }
      else if(k==1)ans.push_back(i+1);
    }
    else if(d[d.size()-1]==i){
      if(b[i-1]<k)ans.emplace_back(i+1);
    }
    else{
      ll p=lower_bound(e.begin(),e.end(),i)-e.begin()-1;
      //if(i==9)cout << e[p] << endl;
      p=e[p];
      if(max(p+c,i+1)>=n)continue;
      if(b[p]+a[max(p+c,i+1)]<k)ans.emplace_back(i+1);
    }
  }


  for(ll i=0;i<ans.size();i++)cout << ans[i] << endl;
  
  //for(ll i=0;i<4;i++)cout << d[i] << " ";

  //cout << b[9] << " " << a[10] <<  endl;

  return 0;
}