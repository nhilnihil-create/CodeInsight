#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

int n;
int num[100001];

main(){
	ll a,b,v,w,t;

	cin >> a >> v >> b >> w >> t;

	if(v>w){
		ll u = v-w;
		ll l = abs(b-a);
		if((double)l/u<=t) cout << "YES" << endl;
		else cout << "NO" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}
