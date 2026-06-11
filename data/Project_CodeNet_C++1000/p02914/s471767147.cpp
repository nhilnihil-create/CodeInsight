#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e18)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
#define YesNo(a) cout<<TO((a),"Yes","No")<<endl;


ll maxSubarrayXOR(vector<ll> set,ll n){
	// https://www.geeksforgeeks.org/find-maximum-subset-xor-given-set/
	const ll INT_BITS = 64;
	ll index = 0;
	for(ll i=INT_BITS-1;i>=0;i--){
		ll maxInd = index;
		ll maxEle = -INF;
		for(ll j=index; j<n; j++){
			if( (set[j] & (1LL<<i))!=0
				&& set[j] > maxEle)
			{
				maxEle = set[j];
				maxInd = j;
			}
		}
		if(maxEle == -INF)continue;
		swap(set[index],set[maxInd]);
		maxInd = index;
		for(ll j=0;j<n;j++){
			if( j!=maxInd && ((set[j]&(1LL<<i))!=0) ){
				set[j] = set[j]^set[maxInd];
			}
		}
		index++;
	}
	ll res = 0;
	for(ll i=0;i<n;i++){
		res ^= set[i];
	}
	return res;
}



int main(){
	ll N,AX=0;
	cin >> N;
	vector<ll> A(N),B(N);
	FOR(i,0,N)cin>>A[i], AX^=A[i];
	FOR(i,0,N)B[i] = A[i]-(AX&A[i]);
	ll ans = maxSubarrayXOR(B,N);
	cout << ans+(AX^ans) << endl;
}

