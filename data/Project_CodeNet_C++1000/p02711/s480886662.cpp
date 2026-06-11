#include <bits/stdc++.h>
using namespace std;
int main(){
	string N;
	cin >> N;
	string ans = "No";
	for(int i=0;i<3;i++){
		if(N[i] == '7')ans = "Yes";
	}
	cout << ans << endl;
}
