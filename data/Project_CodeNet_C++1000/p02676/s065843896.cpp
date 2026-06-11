#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	int k;
	cin>>k>>s;
	if(s.size()<=k){
		cout<<s<<'\n';
	}
	else{
		for(int i=0;i<s.size()-(s.size()-k);i++){
			cout<<s[i];
		}
		cout<<"..."<<'\n';
	}
	return 0;
} 