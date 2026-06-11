#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	
	int ans = 1;
	
	rep(i,n){
		cin >> s.at(i);
	}
	
	sort(s.begin(), s.end());
	
	string mem = s.at(0);
	for(int i = 1; i < n; i++){
		if(mem != s.at(i)){
			ans++;
			mem = s.at(i);
		}
	}
	
	cout << ans << endl;
	
}