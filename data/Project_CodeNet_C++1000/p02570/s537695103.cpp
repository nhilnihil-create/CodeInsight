#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int d,t,s; cin>>d>>t>>s;
	if(d<=t*s) cout << "Yes\n";
	else cout << "No\n";
}
