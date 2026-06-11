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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll T1, T2, A1, A2, B1, B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  if((A1-B1)*T1==-(A2-B2)*T2) {
    cout<<"infinity"<<endl;
    return 0;
  }
  if((A1>B1 && A2>B2>0) || (A1<B1 && A2<B2)) {
    cout<<0<<endl;
    return 0;
  }
  if(abs(A1-B1)*T1>abs(A2-B2)*T2) {
    cout<<0<<endl;
    return 0;
  }
  ll s = abs(abs(A2-B2)*T2-abs(A1-B1)*T1);
  if(abs(A1-B1)*T1%s==0) {
    cout<<abs(A1-B1)*T1/s*2<<endl;
  }
  else {
    cout<<abs(A1-B1)*T1/s*2+1<<endl;
  }
}

