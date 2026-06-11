#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int lim = 1e7+100;
int num_div[lim];
void sieve(int lim){
	for(int i=1;i<lim;i++){
		for(int j=i;j<lim;j+=i){
			num_div[j]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	sieve(n+10);

	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*i*num_div[i];
	}
	cout<<ans<<'\n';

	return 0;
}