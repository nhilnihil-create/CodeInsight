#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, int>Pair;
#define MAX 1e9
struct edge { int to, cost; };
typedef pair<int, int>P;
#define MOD 1000000007

int main(){
  ll N;
  cin>>N;
  if(N%2ll==1ll){cout<<0<<endl;return 0;}
  N/=2ll;
  ll cnt=0ll;
  while(true){
    cnt+=(N/5ll);
    N/=5ll;
    if(N<5ll){break;}
  }
  cout<<cnt;
}