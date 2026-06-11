#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long cnt=0;
	cin >> n;
	vector<int> a(n+1);
	vector<int> b(n);
	
	for(int i=0;i<n+1;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	
	for(int i=0;i<n;++i){
		int c = min(a[i],b[i]);
		cnt += c;
		a[i] -= c;
		b[i] -= c;

		int d = min(a[i+1],b[i]);
		cnt += d;
		a[i+1] -= d;
	}
	cout << cnt << endl;
	return 0;
}