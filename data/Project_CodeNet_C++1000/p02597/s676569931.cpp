#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int l=0,r=s.size()-1;
	int cnt=0;
	while(l<=r){
		while(s[l]=='R'){
			l++;
		}
		
		while(s[r]=='W'){
			r--;
		}
		if(l<r)
		cnt++;
		l++,r--;
	}
	cout<<cnt<<endl;
	return 0;
}