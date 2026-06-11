#include <iostream>
#include <set>
#define ll long long
using namespace std;

int pp[100010];

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		int P;
		cin >> P;
		pp[P]=i;
	}
	multiset<ll> ms{-1, -1, N, N};
	ll ans=0;
	for(int i=N; i>0; --i){
		auto it=ms.insert(pp[i]);
		--it;
		--it;
		ll cc[5];
		for(int j=0; j<5; ++j){
			cc[j]=*it;
			++it;
		}
		ans += ((cc[1]-cc[0])*(cc[3]-cc[2])+(cc[2]-cc[1])*(cc[4]-cc[3]))*i;
	}
	cout << ans << endl;
	return 0;
}