#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin>>str;
	sort(str.begin(), str.end()); 
	if(str[0]==str[1] && str[2]==str[3] && str[1]!=str[2]){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}