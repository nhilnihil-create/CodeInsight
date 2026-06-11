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
  int N;
  cin>>N;
  vector<ll> arr;
  map<ll, ll> amap;
  vector<ll> tmp(N);
  bool can = true;
  for(int i=0;i<N;++i) {
    cin>>tmp[i];
    if(tmp[i]!=0) can = false;
    if(amap[tmp[i]]==0) arr.push_back(tmp[i]);
    amap[tmp[i]]++;
  }
  if(N==3) {
    if((tmp[0]^tmp[1])==tmp[2]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
  }
  if(N%3==0) {
    if(arr.size()==1) {
      if(arr[0]==0) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
      return 0;
    }
    vector<ll> ans;
    ans.push_back(arr[0]);
    ans.push_back(arr[1]);
    amap[arr[0]]--;
    amap[arr[1]]--;
    ll tmpans;
    can = true;
    for(int i=2;i<N;++i) {
      tmpans = ans[ans.size()-1]^ans[ans.size()-2];
      if(amap[tmpans]<=0) can = false;
      amap[tmpans]--;
      ans.push_back(tmpans);
    }
    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else {
    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}
