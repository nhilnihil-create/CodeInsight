#include<bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/2;
const ll MOD = 1e9+7;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;cin>>N;
  if(__builtin_popcountll(N)==1){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  cout<<1<<" "<<N+2<<endl;
  cout<<N+2<<" "<<3<<endl;
  cout<<3<<" "<<N+1<<endl;
  cout<<N+1<<" "<<2<<endl;
  cout<<2<<" "<<N+3<<endl;
  for(ll i=4;i<N;i+=2){
    cout<<N+1<<" "<<i<<endl;
    cout<<N+1<<" "<<i+1<<endl;
    cout<<i<<" "<<i+1+N<<endl;
    cout<<i+1<<" "<<N+i<<endl;
  }
  if(!(N&1)){
    cout<<N-1<<" "<<N<<endl;
    cout<<(N^1^(N-1))<<" "<<2*N<<endl;
  }
  return 0;
}
