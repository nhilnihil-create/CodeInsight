#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	
	bool ans = true;
	
	int n = s.size();
	
	for(int i = 0; i < (n-1)/2; i++){
		if(s.at(i) != s.at(n-i-1)) ans = false;
	}
	
	if(ans) for(int i = 0; i < (n-1)/2 /2; i++){
		if(s.at(i) != s.at((n-1)/2-i-1)){
			ans = false;
		}
	}
	
	if(ans) for(int i = (n+3)/2-1; i < n; i++){
		if(s.at(i) != s.at(n-i-1)) ans = false;
	}

	if(ans) cout << "Yes";
	else cout << "No";
	cout << endl;
	
	return 0;
	
	
}