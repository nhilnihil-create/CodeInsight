#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define Int ll
#define BORDER -1

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n,k;cin>>n>>k;
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  int sum=0;
  for(auto c:a)sum+=c;

  set<int>candidates;
  for(int i=1; i*i<=sum; i++){
    if(sum%i)continue;
    candidates.insert(i);
    candidates.insert(sum/i);
  }

  Int ans = 0;
  for(auto c:candidates){
    vector<Int>ca(n);
    rep(i, n)ca[i]=a[i]%c;

    sort(ca.begin(), ca.end());
    Int psum = 0, msum=0;
    rep(i, n)msum += ca[i];
    if(msum==psum)ans = max<Int>(ans, c);
//cout<<ans<<' '<<msum<<' '<<c<<endl;
if(c== BORDER)cout<<"---"<<endl;
    rrep(i, n){
      msum -= ca[i];
      psum += c-ca[i];
//cout<<psum<<' '<<msum<<endl;
      //if(psum!=msum)continue;
      Int opc = max<Int>(psum, msum);
if(c== BORDER && opc<=k)cout<<opc<<' '<<endl;
if(c== BORDER)cout<<psum<<' '<<msum<<endl;;
      if(opc<=k)ans = max<Int>(ans, c);

    }
if(c== BORDER)cout<<"---"<<endl;

  }

  cout << ans << endl;

  return 0;

  cout<<sum<<endl;
  cout<<candidates.size()<<endl;

  return 0;
}