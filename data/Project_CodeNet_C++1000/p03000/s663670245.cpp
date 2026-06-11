#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	int A[N];
	int count=1, sum=0;
	for (int i=0; i<N; i++) cin >> A[i];
	for (int i=0;;i++){
	    sum+=A[i]++;
	    count++;
	    if (sum>X){
	        count--;
	        break;
	    }
	    if (sum==X) break;
	}
	cout << count << endl;
}