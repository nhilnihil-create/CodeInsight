#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;

int A[200010], B[200010];
priority_queue<pair<int, int>> pq;

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) cin >> A[i];
	for(int i=0; i<N; ++i){
		cin >> B[i];
		pq.push(make_pair(B[i], i));
	}
	ll ans=0;
	while(pq.size()>0){
		int key=pq.top().second;
		pq.pop();
		if(B[key]<A[key]){
			cout << -1 << endl;
			return 0;
		}
		if(B[key]>A[key]){
			if((B[key]-A[key])%(B[(key+N-1)%N]+B[(key+1)%N])==0){
				ans += (B[key]-A[key])/(B[(key+N-1)%N]+B[(key+1)%N]);
				B[key]=A[key];
			}else{
				ans += B[key]/(B[(key+N-1)%N]+B[(key+1)%N]);
				B[key] %= (B[(key+N-1)%N]+B[(key+1)%N]);
				if(B[key]>=max(B[(key+N-1)%N], B[(key+1)%N])){
					cout << -1 << endl;
					return 0;
				}
				pq.push(make_pair(B[key], key));
			}
		}
	}
	cout << ans << endl;
	return 0;
}