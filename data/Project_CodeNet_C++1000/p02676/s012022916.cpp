#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n, len;
	cin >> n;
	cin >> s;
	len = s.size();
	if(len <= n){
		cout << s << endl;
	}else{
		for(int i=0; i<n; i++){
			cout << s[i];
		}	
		cout << "...";

	}
	
	return 0;
}