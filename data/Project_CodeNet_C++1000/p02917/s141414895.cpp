#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int b[n+1];
	b[0]=1000000; b[n]=1000000;
	for(int i=1; i<n; i++){
		cin >> b[i];
	}
	vector<int> a(n);
	for(int i=1; i<n+1; i++){
		a.push_back(min(b[i],b[i-1]));
	}
	int sum=0;
	for(auto x:a){
		sum += x;
	}
	cout << sum;
	return 0;
}