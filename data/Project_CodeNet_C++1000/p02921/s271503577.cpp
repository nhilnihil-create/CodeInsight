#include <iostream>
#include <string>

#define mod 1000000000+7;
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	string s,t; cin >> s >> t;
	int ans{};
	for(int i{}; i<s.size(); i++){
		if(s[i]==t[i]) ++ans;
	}

	cout << ans << "\n";
}