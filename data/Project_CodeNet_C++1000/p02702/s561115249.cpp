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
  vector<int> ten(10);
  for(int i=0;i<10;++i) ten[i] = i;
  vector<int> arr;
  map<int, int> amap;
  int num;
  int amari = 0;
  for(int i=S.size()-1;i>=0;--i) {
    num = S[i]-'0';
    amari += ten[num];
    amari %= 2019;
    if(amap[amari]==0) arr.push_back(amari);
    amap[amari]++;
    for(int j=0;j<10;++j) {
      ten[j] = ten[j]*10%2019;
    }
  }
  int ans = 0;
  for(int i=0;i<arr.size();++i) {
    ans += amap[arr[i]]*(amap[arr[i]]-1)/2;
  }
  cout<<ans+amap[0]<<endl;
}

