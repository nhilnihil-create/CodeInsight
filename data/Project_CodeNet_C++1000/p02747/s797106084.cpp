#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int n=s.size();
	if (n%2) {
		cout<<"No";
		return 0;
	}
	bool ok=true;
	for (int i=0; i<n; i++){
		if(i%2) {
			if(s[i]!='i') ok=false;
		} else {
			if (s[i]!='h') ok=false;
		}
	}
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}
