#include <bits/stdc++.h>
using namespace std;

int main(void){
	string str;
	int q;
	cin >> str;
	cin >> q;
	string cmd;
	int t1,t2;
	string t3;
	for(int i = 0; i < q; i++){
		cin >> cmd >> t1 >> t2;
		if(cmd == "replace"){
			cin >> t3;
			str.replace(t1,t2-t1+1,t3);
		}else if(cmd == "reverse"){
			reverse(str.begin()+t1, str.begin()+t2+1);
		}else if(cmd == "print"){
			cout << str.substr(t1,t2-t1+1) << endl;
		}
	}
}
