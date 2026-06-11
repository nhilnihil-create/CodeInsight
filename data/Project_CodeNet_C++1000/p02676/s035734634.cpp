#include<bits/stdc++.h>
using namespace std;

int main(){
	int k;
	cin>>k;
	string s;
	cin>>s;
	if(s.size()<=k){
		cout<<s<<endl;
	}
	else{
		string a;
		for(int i=0;i<k;i++){
			a+=s.at(i);
		}
		cout<<a<<"..."<<endl;
	}
}