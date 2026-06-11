#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	double sum=0;
	for (int i=0; i<N; i++) {
	    int A;
        cin >> A;
	    sum+=1.0/A;
	}
	double ans=1.0/sum;
	cout << setprecision(20) << ans << endl;
}
