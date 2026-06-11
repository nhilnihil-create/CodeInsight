#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
const ll MOD=1000000007LL;

int main(){
	ll N;
	string S;
	cin >> N >> S;
	ll ans = 1;
	ll cnt = 0;//まだ結ばれてない
	FOR(i,0,2*N){
		if( (cnt%2==0&&S[i]=='B') || (cnt%2==1&&S[i]=='W') ){
			cnt++;
		}else{
			(ans *= cnt) %= MOD;
			cnt--;
		}
		if(cnt<0){
			cout << 0 << endl;
			return 0;
		}
	}
	FOR(i,1,N+1){
		(ans*=i)%=MOD;
	}
	cout << (cnt!=0 ? 0LL : ans) << endl;
}