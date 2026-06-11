#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1000100;

int N,a,b;
int A[MAXN];
int f2[MAXN];
string S;
int C[MAXN];

bool is2(){
  if (min(C[0]+C[2], C[1]+C[3]))return 0;
  if (C[1])for (int i=0;i<N;++i)--A[i];
  int pp=0;
  int tot=0;
  for(int i=0;i<N;++i){
    if (A[i]==2){
      if (pp==0)tot++;
    }
    pp += f2[N-1-i];
    pp -= f2[i+1];
  }
  if (tot%2==1)return 1;
  return 0;
}

int main(){
  cin>>N>>S;
  for (int i=0;i<N;++i)A[i] = S[i] - '0';
  for (int i=0;i<N;++i)C[A[i]]++;
  ll pp = 0;
  ll tot = 0;
  for (int jump=1;jump<=N;jump*=2)for(int i=jump;i<=N;i+=jump)++f2[i];

  for(int i=0;i<N;++i){
    if (A[i]%2==1){
      if (pp==0)tot++;
    }
    pp += f2[N-1-i];
    pp -= f2[i+1];
  }
  if (tot%2==1){
    cout<<1;
    return 0;
  }
  if (is2()){
    cout<<2;
    return 0;
  }
  cout<<0;
  return 0;
}