//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	string s;
	cin>>s;
	for(int i=0;i<3;i++){
		if(s[i] == s[i+1]){
			cout<<"Bad"<<endl;
			return 0;
		}
	}	

	cout<<"Good"<<endl;


	

	return 0;
}