#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sz5 100005

ll BIT[sz5*5];

void update(ll idx, ll n, ll val){
	while(idx<=n){
		BIT[idx]+=val;
		idx+=(idx&(-idx));
	}
}

ll query(ll idx){
	ll ans=0;
	while(idx){
		ans+=BIT[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}

int main() {
	FAST

	ll n,q,la,lb,num;
	cin>>n>>q;
	for(la=1;la<=n;la++){
		cin>>num;
		update(la, n, num);
	}

	while(q--){
		ll ch, a, b;
		cin>>ch>>a>>b;

		if(ch==0)
			update(a+1, n, b);
		else
			cout<<query(b)-query(a)<<endl;
	}

	return 0;
}