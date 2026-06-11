#include <bits/stdc++.h>
using namespace std;
int main (){
	string s;
	int cont =0;
	cin>> s;
	reverse(s.begin(), s.end());
	
	while(s.size()){
		if (s.back() != s[0]) cont ++;
		s.pop_back();
		if (s.size()) s.erase(s.begin());
	}
	cout << cont;
	
	return 0;
}