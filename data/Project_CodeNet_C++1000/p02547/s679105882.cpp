#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector <vector <int>> v (n,vector <int> (2,0));
	for(int i=0;i<n;++i){
		int d1,d2;
		cin>>d1>>d2;
		v[i][0] = d1;
		v[i][1] = d2;
	}
	bool ok = true;
	for(int i=0;i<=n-3;++i){
		ok = true;
		for(int j=0;j<3;++j){
			if(v[i+j][0]!=v[i+j][1]){
				ok = false;
				break;
			}
		}
		if(ok) break;
	}
	if(ok) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}