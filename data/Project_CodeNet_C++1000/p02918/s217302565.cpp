#include<bits/stdc++.h>
using namespace std;
int arr[105];

int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int happy = 0;
	int rl = 0;
	int lr = 0;
	int l = 0;
	int r = 0;
	
	for(int i=1; s[i]; i++){
		if(s[i]==s[i-1]) happy++;
		else{
			if(s[i]=='R') lr++;
			else rl++;
		}
	}
	int two = min(lr,rl);
	lr-=two;
	rl-=two;
	int one = lr+rl;
	
	happy+=2*min(k,two);
	k-=two;
	if(k>0) happy+=min(k,one);
	cout<<happy;
}