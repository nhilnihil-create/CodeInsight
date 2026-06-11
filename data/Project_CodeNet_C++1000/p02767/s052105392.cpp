#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
  ll n;
  cin>>n;
  ll sum=0;
  vll x(n);
  rell(i,n){
      cin>>x[i];
      sum+=x[i];
  }
  ll p=sum/n;
  if(sum<=n*p+n/2){
      
  }
  else p+=1;
  ll ans=0;
  rell(i,n){
      ans+=(x[i]-p)*(x[i]-p);
  }
  cout<<ans<<endl;
  
}
