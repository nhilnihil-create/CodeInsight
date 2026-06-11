#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int lr = 0;
	int rl = 0;
	int ret = 0;
	for(int i=1; i<n; i++){
		if(s[i-1]==s[i]) ret++;
		else{
			if(s[i]=='R') lr++;
			else rl++;
		}
	}
	int two = min(lr,rl);
	if(k>=two){
		ret+=2*two;
		k-=two;
		int left = max(lr,rl)-two;
		ret+=min(left,k);
	}
	else ret+=2*k;
	cout<<ret;
}