#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define INF INT_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)


constexpr ll mod_number = 1000000000+7;

ll repeatSquare(ll a,ll n,ll mod){
	ll answer = 1;

	while(n > 0){
		if(n & 1){	//nが奇数なら先に答えの方にa^1をかけておく事で残りのa^n-1を2分割できるようにしている
			answer = answer * a % mod;
		}
		a = a * a % mod;
		n = n>>1;	//nを2で割ると同じ
	}
	return answer;
}

int main(){

	ll n, a, b;
	cin>>n>>a>>b;

	ll enable_hanataba = (repeatSquare(2,n,mod_number) - 1) % mod_number;

	ll nCa = 1;	
	ll nCb = 1;	
	
	for(ll i = 0; i < a; i++){
		nCa = nCa * (n-i) % mod_number;
		nCa = nCa * (repeatSquare(i+1,mod_number-2,mod_number) % mod_number) % mod_number;
	}	
	for(ll i = 0; i < b; i++){
		nCb = nCb * (n-i) % mod_number;
		nCb = nCb * (repeatSquare(i+1,mod_number-2,mod_number) % mod_number) % mod_number;
	}
	//cout<<enable_hanataba<<endl;
	//cout<<nCa<<" : "<<nCb<<endl;
	
	ll ans = enable_hanataba - (nCa + nCb)%mod_number;
	
	if(ans < 0)ans = ans + mod_number;
	cout<<ans<<endl;
	return 0;
}


//(2^n-1) - nCa - nCb : 0本の花束は存在しないので
//
//rei : 15 - 4 - 4 = 7
//
//nCa = n
//
//
//15 % 2 = (30 / 2 )% 2 =  (30%2 / 2) % 2
