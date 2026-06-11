#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int n;
	string s;
	cin >> n >> s;

	vector<int> r;
	vector<int> g;
	vector<int> b;
	for(int i=0;i<n;i++){
		if(s[i]=='R') r.push_back(i);
		if(s[i]=='G') g.push_back(i);
		if(s[i]=='B') b.push_back(i);
	}

	int ans = 0;
	for(int i=0;i<r.size();i++){
		for(int j=0;j<g.size();j++){
			int ii = r[i];
			int jj = g[j];
			
			ans += b.size();
			if(binary_search(b.begin(),b.end(), 2*jj-ii)) ans--;
			if(binary_search(b.begin(),b.end(), 2*ii-jj)) ans--;
			if((ii+jj)%2==0 && binary_search(b.begin(),b.end(), (ii+jj)/2)) ans--;
			
		}
	}

	cout << ans << endl;

	return 0;
}