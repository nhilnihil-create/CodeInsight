#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i=0; i<N; i++){
	    cin >> A[i];
	}
	int ans=100000000;
	for (int i=0; i<=100; i++){
	    int cost=0;
	    for (int j=0; j<N; j++){
	        cost+=(A[j]-i)*(A[j]-i);
	    }
	    ans=min(ans, cost);
	}
	cout << ans << endl;
}
