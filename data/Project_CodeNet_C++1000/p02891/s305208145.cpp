#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  ll K;
  cin>>K;
  string tmp = S;
  for(int i=0;i<5;++i) {
    for(int j=0;j<S.size();++j) tmp.push_back(S[j]);
  }
  for(int i=0;i<tmp.size()-1;++i) {
    if(tmp[i]==tmp[i+1]) tmp[i+1] = '*';
  }
  char yey = tmp[2*S.size()-1];
  ll num;
  for(int i=2;i<5;++i) {
    if(tmp[i*S.size()+S.size()-1]==yey) {
      num = i-1;
      break;
    }
  }
  ll arr[num+1];
  for(int i=0;i<=num;++i) arr[i] = 0;
  for(int i=1;i<=num;++i) {
    for(int j=S.size();j<i*S.size()+S.size();++j) {
      if(tmp[j]=='*') arr[i]++;
    }
  }
  int first = 0;
  for(int i=0;i<S.size();++i) {
    if(tmp[i]=='*') first++;
  }
  ll ans = first + (K-1)/num*arr[num];
  if((K-1)%num>0){
    if(S[0]!=S[S.size()-1]) {
      ans += arr[(K-1)%num];
    }
    else {
      if(yey=='*'){
        ans += arr[(K-1)%num];
      }
      else {
        tmp = "";
        for(int i=0;i<(K-1)%num;++i) {
          for(int j=0;j<S.size();++j) tmp.push_back(S[j]);
        }
        tmp[0] = '*';
        for(int i=0;i<tmp.size()-1;++i) {
          if(tmp[i]==tmp[i+1]) tmp[i+1] = '*';
        }
        for(int i=0;i<tmp.size();++i) {
          if(tmp[i]=='*') ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}

