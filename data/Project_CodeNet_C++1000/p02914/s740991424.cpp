#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll a[100010];

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) cin >> a[i];
	ll ans=0;
	for(int d=59; d>=0; --d){
		ll t=((ll) 1<<d);
		int cnt=0;
		for(int i=0; i<N; ++i){
			if((a[i])&t) ++cnt;
		}
		if(cnt%2==1){
			ans += t;
			for(int i=0; i<N; ++i){
				if((a[i])&t) a[i] -= t;
			}
		}
	}
	int now=0;
	for(int d=59; d>=0; --d){
		ll t=((ll) 1<<d);
		for(int i=now; i<N; ++i){
			if((a[i])&t){
				swap(a[now], a[i]);
				for(int j=0; j<N; ++j){
					if(j!=now && (a[j])&t){
						a[j] ^= a[now];
					}
				}
				++now;
				break;
			}
		}
		int px=0;
		for(int i=0; i<N; ++i){
			if((a[i])&t) ++px;
		}
		if(px%2==1){
			ans += t*2;
		}
	}
	cout << ans << endl;
	return 0;
}