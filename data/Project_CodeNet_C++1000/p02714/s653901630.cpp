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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  string S;
  cin>>S;
  ll Rarr[N+1], Garr[N+1], Barr[N+1];
  for(int i=0;i<=N;++i) {
    Rarr[i] = 0;
    Garr[i] = 0;
    Barr[i] = 0;
  }
  for(int i=0;i<S.size();++i) {
    if(S[i]=='R') Rarr[i+1]++;
    if(S[i]=='G') Garr[i+1]++;
    if(S[i]=='B') Barr[i+1]++;
  }
  for(int i=1;i<=N;++i) {
    Rarr[i] += Rarr[i-1];
    Garr[i] += Garr[i-1];
    Barr[i] += Barr[i-1];
  }
  ll ans = 0;
  for(int i=0;i<N;++i) {
    for(int j=i+1;j<N;++j) {
      if(S[i]==S[j]) continue;
      if((S[i]=='R' && S[j]=='G') || (S[i]=='G' && S[j]=='R')) {
        ans += Barr[N]-Barr[j+1];
        if(2*j-i<N && S[2*j-i]=='B') ans--;
      }
      if((S[i]=='R' && S[j]=='B') || (S[i]=='B' && S[j]=='R')) {
        ans += Garr[N]-Garr[j+1];
        if(2*j-i<N && S[2*j-i]=='G') ans--;
      }
      if((S[i]=='B' && S[j]=='G') || (S[i]=='G' && S[j]=='B')) {
        ans += Rarr[N]-Rarr[j+1];
        if(2*j-i<N && S[2*j-i]=='R') ans--;
      }
    }
  }
  cout<<ans<<endl;
}

