/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

void solve(int test_case) {//210
	int n;
	cin>>n;
	ull ans = 1;
	vector<ull> arr(n,0);
	int mx = INT_MIN;
	REP(i,1,n){
		int val;
		cin>>val;
		if(i==1&&val!=0) {
			cout<<0;
			return;
		}
		if(i!=1&&val==0){
			cout<<0;
			return;
		}
		mx=max(mx,val);
		arr[val]++;
	}
	REP(i,0,mx) {
		if(arr[i]==0){
			cout<<0;
			return;
		}
	}
	REP(i,1,mx) {
		ull mp = modpow(arr[i-1], arr[i], 998244353ull);
		ans = (ans * mp)%998244353ull;
	}
	cout<<ans;
}//no. current ^ no. child

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
