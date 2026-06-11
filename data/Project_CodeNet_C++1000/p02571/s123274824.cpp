#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s,t; cin>>s>>t;
	int aans=0x7fffffff;
	for(size_t i=0; i+t.size()<=s.size(); i++) {
		int ans=0;
		for(size_t j=0; j<t.size(); j++) {
			if(s[i+j]!=t[j]) {
				ans++;
			}
		}
		aans=min(aans,ans);
	}
	cout << aans << '\n';
}