#include<bits/stdc++.h>
using namespace std;
vector<int>hasher[105];

int main(){
	int n;
	cin>>n;
	long long ret = 0;
	
	for(int i=1; i<=n; i++){
		if(i%10==0) continue;
		int curr = 1;
		while(curr*10<=i) curr*=10;
		int fir = i/curr;
		int sec = i%10;
		hasher[fir*10+sec].push_back(i);
	}
	for(int i=1; i<=n; i++){
		if(i%10==0) continue;
		int curr = 1;
		while(curr*10<=i) curr*=10;
		int fir = i/curr;
		int sec = i%10;
		ret+=hasher[sec*10+fir].size();

	}
	cout<<ret;
}