#include <bits/stdc++.h>
 
using namespace std;

#define esp 1e-9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	vector<long long int> indx;
	indx.push_back(0);
	vector<long long int> b;
	b.push_back(0);
	vector<long long int> c;
	c.push_back(0);
	long long int t=n,tt=n-1;
	while(n--){
		long long int x;
		cin>>x;
		indx.push_back(x);
	}
	while(t--){
		long long int x;
		cin>>x;
		b.push_back(x);
	}
	while(tt--){
		long long int x;
		cin>>x;
		c.push_back(x);
	}
	long long int ans=0;
	for(long long int i=1;i<indx.size();i++){
		long long int xx=indx[i];
		ans+=b[xx];
		if(indx[i-1]==xx-1){
			ans+=c[xx-1];
		}
	}
	cout<<ans;
	return 0;
}