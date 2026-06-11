#include <bits/stdc++.h>
#include <string>

#define rep(i,n) for(i=0;i<(n);i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

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
    for(int i=0;i<a;i++){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    for(int i=0;i<a;i++){
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
	    for(int i=0;i<t;i++){ fact[i+1]=fact[i]*(i+1)%MOD;}
	fact_inv[t]=power(fact[t], MOD-2);
	for(int i=0;i<t;i++){ fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;}
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}
  
int main()
{
	cin.tie(0);	ios::sync_with_stdio(false);

  int i,j;
  int A,B,M; cin >> A >> B >> M;
  int a[A],b[B];
  int c,x,y;
  int minA=1000000,minB=1000000;
  int ans = 0;
  rep(i,A){cin >> a[i];if(minA>a[i]){minA=a[i];}}
  rep(i,B){cin >> b[i];if(minB>b[i]){minB=b[i];}}
  ans = minA+minB;
  rep(i,M){
      cin >> x >> y >> c;
      int tmp = a[x-1] + b[y-1] - c;
      ans = min(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}
