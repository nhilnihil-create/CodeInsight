#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> P(n), Q(n), A(n);
	for (int i=0; i<n; i++) cin >> P[i];
	for (int i=0; i<n; i++) cin >> Q[i];
	for (int i=0; i<n; i++) A[i] = i+1;

	int sP=0, sQ=0;
	do
	{
		if (!lexicographical_compare(A.begin(), A.end(), P.begin(), P.end())) sP++;
		if (!lexicographical_compare(A.begin(), A.end(), Q.begin(), Q.end())) sQ++;
	} while(next_permutation(A.begin(), A.end()));

	cout<<abs(sP-sQ)<<"\n";

	return 0;
}