#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	map<LL,LL> mp;
	LL a,b;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		mp[b] += a;
	}
	// keisan
	LL sum = 0;
	int flag = 1;
	for(auto x:mp){
		sum += x.second;
		if(x.first < sum){
			flag = 0;
			break;
		}
	}
	// syutsuryoku
	if(flag){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}