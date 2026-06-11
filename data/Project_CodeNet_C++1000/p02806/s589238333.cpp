#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<string> s(n);
	vector<int> t(n); 
	for (int i=0; i<n; i++)
		cin>>s[i]>>t[i];
	string x; cin>>x;
	bool ok=false;
	int ret=0;
	for (int i=0; i<n; i++) { 
		if (ok) ret+=t[i];
		if (s[i]==x) ok=true;
	}
	cout<<ret<<endl;
	return 0;
}
