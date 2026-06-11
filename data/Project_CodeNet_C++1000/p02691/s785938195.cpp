#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	long long A[N];
	vector<long long> L, R;
	for(long long i=0;i<N;i++){
		cin >> A[i];
		L.push_back(i - A[i]);
		R.push_back(i + A[i]);
	}
	L.push_back(1000000001);
	R.push_back(1000000002);
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	long long i = 0, j = 0;
	long long ans = 0;
	while(i < N && j < N){
		if(L[i] < R[j])i++;
		else if(L[i] == R[j]){
			long long it = i, jt = j;
			while(L[it] == L[it+1])it++;
			while(R[jt] == R[jt+1])jt++;
			ans += (it - i + 1) * (jt - j + 1);
			i = it + 1;
			j = jt + 1;
		}
		else j++;
	}
	cout << ans << endl;
}