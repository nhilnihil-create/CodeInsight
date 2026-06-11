#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	string s;
	string t;
	cin>>s;
	cin>>t;
	
	int tot = 0;
	int len = s.length();
	for(int i=0;i<len;i++){
		if(s[i]!=t[i]) tot++;
	}
	cout<<tot<<endl;
} 