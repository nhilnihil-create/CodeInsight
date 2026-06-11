#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,k;
	cin >> n >> k;
	vector<long long> a(n);
	for(long long i=0;i<n;i++) cin >> a[i];
	for(long long i=0;i<k;i++){
		vector<long long>b(n+1,0);
		for(long long j=0;j<n;j++){
			long long l=max(0LL,j-a[j]);
			long long r=min(n,j+a[j]+1);
			b[l]++;
			b[r]--;
		}
		for(long long j=0;j<n;j++){
			b[j+1]+=b[j];
		}
		b.pop_back();
		if(a==b) break;
		a=b;
	}
	for(long long i=0;i<n;i++) cout << a[i] << " ";
	cout << endl;
}
