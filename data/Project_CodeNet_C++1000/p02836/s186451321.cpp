#include<iostream>
#include<string>
using namespace std;

int solve(string s){
	int ans=0;
	for(int i=0; i<s.length()/2; i++){
		if(s[i] != s[s.length()-1-i]){
			ans++;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
    cin >> str;
	cout << solve(str);
	return 0;
}