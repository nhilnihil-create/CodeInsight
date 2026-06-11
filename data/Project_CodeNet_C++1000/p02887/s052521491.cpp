#include<bits/stdc++.h>
using namespace std;
	
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string res;
	for(int i = 0; i < n; i++){
		if(s[i] != res[res.size()-1]){
			res += s[i];
		}
	}
	cout << res.size() << endl;

}

