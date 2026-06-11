#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main(){
	string s, t;
	cin >> s >> t;

	int len = s.size();
	int flag = 0;

	for(int i = 0; i < len; i++){
		if(s[i] != t[i]){
			flag = 1;
			break;
		}
	}
	
	if(!flag && s.size() + 1 == (t.size() )){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

	return 0;
}