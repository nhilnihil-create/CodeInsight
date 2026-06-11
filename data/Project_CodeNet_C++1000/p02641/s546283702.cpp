#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
	int x,n;
	cin >> x >> n;
	vector<int> p;
	rep(i,n){
		int t; cin >> t;
		p.push_back(t);
	}
	vector<int> np;
	for(int i=0; i<=101; i++){
		bool f=true;
		for(int j=0; j<(int)p.size(); j++){ if(i==p[j]) f=false;}
		if(f)np.push_back(i);
	}
	sort(np.begin(),np.end());

	int diff=1e9;
	int ans=0;
	for(int i=0; i<(int)np.size(); i++){
		if(diff > abs(np[i]-x)){
			diff = abs(np[i]-x);
			ans = np[i];
		}
	}

	cout << ans << endl;

	return 0;

}
