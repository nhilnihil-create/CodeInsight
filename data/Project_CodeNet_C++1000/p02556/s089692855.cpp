#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long>plus;
	vector<long long>minus;
	while(n--){
		long long x,y;
		cin>>x>>y;
		plus.push_back(x+y);
		minus.push_back(x-y);
	}
	sort(plus.begin(),plus.end());
	sort(minus.begin(),minus.end());
	long long ret = 0;
	ret = max(ret,plus[plus.size()-1]-plus[0]);
	ret = max(ret,minus[minus.size()-1]-minus[0]);
	cout<<ret;
}