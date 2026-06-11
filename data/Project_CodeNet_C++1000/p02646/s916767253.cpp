#include <iostream>
using namespace std;

int main() {
	int A, B, V, W, T;
	cin>>A>>V;
	cin>>B>>W;
	cin>>T;
	if(W > V) {
		cout<<"NO\n";
	} else {
		int v_rel = V-W;
		int distance = max(A-B, B-A);
		long long distance_covered = (long long)v_rel*T;
		if(distance_covered >= (long long)distance) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}