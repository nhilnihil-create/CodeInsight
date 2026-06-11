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
  string S1, S2, S3;
  cin>>S2;
  int Q;
  cin>>Q;
  int query, f;
  char c;
  bool gyaku = false;
  for(int i=0;i<Q;++i) {
    cin>>query;
    if(query==1) {
      gyaku ^= 1;
    }
    else {
      cin>>f>>c;
      if(gyaku) {
        if(f==1) S3.push_back(c);
        else S1.push_back(c);
      }
      else {
        if(f==1) S1.push_back(c);
        else S3.push_back(c);
      }
    }
  }
  if(gyaku) {
    reverse(S2.begin(), S2.end());
    reverse(S3.begin(), S3.end());
    cout<<S3+S2+S1<<endl;
  }
  else {
    reverse(S1.begin(), S1.end());
    cout<<S1+S2+S3<<endl;
  }
}

