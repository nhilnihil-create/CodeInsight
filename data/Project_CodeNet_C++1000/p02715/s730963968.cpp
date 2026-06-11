#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1'000'000'007;
const int NN=100002;


ll add(ll x, ll y) { return ((x + y) % MOD + MOD) % MOD;}
ll sub(ll x, ll y) { return ((x - y) % MOD + MOD) % MOD; }
ll mul(ll x, ll y) { return x * y % MOD; }

bitset<NN> is; int mu[NN];
void mobiusSieve() {
  for (int i = 1; i < NN; ++i) mu[i] = 1;
  for (int i = 2; i < NN; ++i) if (!is[i]) {
  for (int j = i; j < NN; j += i){
  is[j] = 1;
  mu[j] *= -1;
  }
 
  for (long long j = 1LL*i*i; j < NN; j += i*i)
  mu[j] = 0;
 
}
}
 


ll pow(ll a, ll b, ll MOD){
  if (b==0) return 1;
  else if (b%2==0){
    ll temp=pow(a,b/2,MOD);
    return temp*temp%MOD;
  }
  else{
    return a*pow(a,b-1,MOD)%MOD;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  mobiusSieve();  
  int N,K;
  cin >> N >> K;
  ll ans=0;
  ll check=0;
  for (ll i=1; i<=K; i++){
    for (ll j=1; j<=K/i; j++){
      ll temp=mul(mu[j],pow(K/(i*j),N,MOD));
      ans=add(ans,mul(i,temp));


    }    
    //ans=add(ans,mul(i,sub(pow(temp,N,MOD),pow(temp-1,N,MOD))));
    //check=add(check,mul(i,sub(pow(temp,N,MOD),pow(temp-1,N,MOD))));

  }
  cout<<ans%MOD<<endl;
  //cout<<check%MOD<<" "<<pow(K,N,MOD)<<endl;




}