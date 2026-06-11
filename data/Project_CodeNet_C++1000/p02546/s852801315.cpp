#include<bits/stdc++.h>
using namespace std;
int main(){
	string st,st1="s";
	cin>>st;
	if(st.substr(st.size()-1)==st1){
		st+='e';
		st+='s';
	}
	else st+='s';
	cout<<st;
}