#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string inp;
	string ord;
	map<string,bool> m;

	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> inp;
		if(inp =="insert"){
			cin >> ord;
			m[ord] = 1;
		}else if(inp == "find"){
			cin >> ord;
			if(m[ord]){
				cout << "yes" << endl;
			}else{
				cout << "no" << endl;
			}
		}
	}
	return 0;
}