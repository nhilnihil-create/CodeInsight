#include <bits/stdc++.h>
using namespace std;

int change(string s,char c,int k){
	int ans=0;
	char g;
	if(c=='L'){
		g='R';
	}
	else{
		g='L';
	}
	
	for(int i=0;i<s.size();i++){
		if(s[i]==c){		
		while(true){
			if(k<=0||i>=s.size()){
				break;
			}
		
		if(s[i]!=c){
			k--;
			break;
		}
		
			s[i]=g;
			i++;
		}
		
	}
	}
	for(int i=0;i<s.size()-1;i++){
		if(s[i]==s[i+1]){
			ans++;
		}
	}
	
	return ans;
}
int main() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int out=-1e5;
	out=max(out,change(s,'R',k));
	out=max(out,change(s,'L',k));
	
cout<<out;
}