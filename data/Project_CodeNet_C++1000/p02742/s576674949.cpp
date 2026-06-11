#include <bits/stdc++.h>
#include <string>
  
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
typedef long long ll;

const ll MOD=1000000007ll;
const int MAX=5100000;

using namespace std;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

void inputArray(int * p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    rep(i, a){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}

ll fact[MAX], fact_inv[MAX];

ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

// nCr
ll comb(ll n, ll r){
	ll t=1000000;
	fact[0]=1;
	REP(i, t) fact[i+1]=fact[i]*(i+1)%MOD;
	fact_inv[t]=power(fact[t], MOD-2);
	FORR(i, 0, t) fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}
  
int main()
{
  ll H,W; cin >> H >> W;
  if(H==1 || W==1){cout << 1 << endl;}
  else{cout << (ll)(H*W+1)/2 << endl;}

  return 0;
}
