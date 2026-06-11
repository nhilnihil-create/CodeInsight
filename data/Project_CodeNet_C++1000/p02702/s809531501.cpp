#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  string S;
  cin >> S;
  int N=S.size();
  
  vi count(2019);
  int ten=1,sum=0;
  count[0]++;
  rep(i,N) {
    sum=(sum+(S[N-i-1]-'0')*ten)%2019;
    ten=ten*10%2019;
    count[sum]++;
  }
  
  ll ans=0;
  rep(i,2019) ans+=(ll)count[i]*(count[i]-1)/2;
  cout << ans << endl;
}
