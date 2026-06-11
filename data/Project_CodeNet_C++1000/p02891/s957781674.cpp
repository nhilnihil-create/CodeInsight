#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	long long k;
	cin>>s>>k;
	long long cnt=0;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			cnt++;
			i++;
		}
	}
	int strk1=1, strk2=1;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[0]) strk1++;
		else break;
	}
	for(int i=s.size()-2;i>=0;i--){
		if(s.back()==s[i]) strk2++;
		else break;
	}
	if(strk1==(int)s.size()){
		cout<<(long long)(s.size())*k/2;
	}
	else{
		if(strk1%2==1 && strk2%2==1 && s[0]==s.back()){
			cout<<cnt*k+k-1;
		}
		else{
			cout<<cnt*k;
		}
	}
}