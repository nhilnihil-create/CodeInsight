#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	int N; cin>>N;
	vector<int> X(N); rep(i,N) cin>>X[i];

	int mimu = 1e9;
	for(int i=1; i<=100; i++){
		int sum=0;
		for(int j=0; j<X.size(); j++){
			sum += (i-X[j])*(i-X[j]);
		}
		mimu = min(mimu,sum);
	}
	cout << mimu << endl;
}
