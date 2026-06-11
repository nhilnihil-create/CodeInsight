#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define itn int
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

int main(){
  ll t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if(a1*t1+a2*t2==b1*t1+b2*t2){
    cout << "infinity" << endl;
    return 0;
  }
  if((a1>b1&&a2>b2)||(a1<b1&&a2<b2)){
    cout << "0" << endl;
    return 0;
  }
  ll fd=abs(a1-b1)*t1;
  ll sd=abs(a2-b2)*t2;
  if(fd>sd){
    cout << "0" << endl;
    return 0;
  }
  ll fsd=abs(fd-sd);
  ll ans=fd/fsd*2+1;
  if(fd%fsd==0) ans--;
  cout << ans << endl;
}