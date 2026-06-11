//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

bool pal(string s){
	int n = s.size();
	if(n  & 1)return false;
	n/=2;
	string s1 = s.substr(0,n);
	string s2 = s.substr(n,n);
	return s1 == s2; 

}

int main(){
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(pal(s)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}


	

	return 0;
}