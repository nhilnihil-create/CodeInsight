/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll K,N,T;
/*ll freq[200005];*/
void solve(){
	 /*memset(freq,0,sizeof(freq));*/
	cin>>N>>K;
    ll ans = 0;
	ll a[N];
	for(ll i = 0 ; i<N ; i++){
		cin>>a[i];
		if(a[i] >= K)
			ans++;
	}

	cout<<ans<<'\n';


}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
  solve();

	return 0;
}	