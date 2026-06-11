#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N;
  cin>>N;
  vl a(N),b(N);
  rep(i,N){
    cin>>a[i];
    b[i]=a[i];
  }
  sort(b.begin(),b.end());
  ll fi=b[N-1],se=b[N-2];
  for(int i=0;i<N;i++){
    if(a[i]==fi){
      cout<<se<<endl;
    }
    else{
      cout<<fi<<endl;
    }
  }
}
