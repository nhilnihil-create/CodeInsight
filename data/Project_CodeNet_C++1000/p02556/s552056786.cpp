#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll sa[200010], wa[200010];

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		ll x, y;
		cin >> x >> y;
		sa[i]=x-y, wa[i]=x+y;
	}
	sort(sa, sa+N);
	sort(wa, wa+N);
	cout << max(sa[N-1]-sa[0], wa[N-1]-wa[0]) << endl;
	return 0;
}