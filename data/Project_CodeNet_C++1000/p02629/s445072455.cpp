#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,k;
	cin >> n;
	
	string s="";
	char c;

	while(n>0){
		n--;
		k=n%26;
		n/=26;
		c='a'+k;
		s.push_back(c);
	}
	reverse(s.begin(),s.end());
	cout << s << endl;
	return 0;
}