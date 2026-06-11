#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	cin>>n;
	char start=n[0];
	string ans;
	for(int i=1;i<4;i++){
		if(n[i]==start){
			ans="Bad";
			break;
		}
		start=n[i];
		ans="Good";
	}
	cout<<ans<<endl;
}