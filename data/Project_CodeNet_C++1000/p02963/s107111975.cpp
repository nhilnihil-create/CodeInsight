#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll s;
	cin >> s;
	ll max = 1000000000;
	
	ll d = s/max + 1;
	if(d == max + 1){
		cout << "0 0 1000000000 1 " << 0 << " " << max << endl;
	}else{
		ll c = max- s%max;
		cout << "0 0 1000000000 1 " << c << " " << d << endl;
		return 0;
	}
}
