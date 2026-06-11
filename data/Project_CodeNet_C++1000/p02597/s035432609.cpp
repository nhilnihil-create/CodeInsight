#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	int red[n]={0};
	for(int i=0; s[i]; i++){
		if(s[i]=='R') red[i]++;
		if(i) red[i]+=red[i-1];
	}
	
	int minchange = red[n-1];
	for(int i=0; i<n; i++){
		 int before_white = (i+1)-red[i];
		 int after_red = red[n-1]-red[i];
		 minchange = min(minchange,max(before_white,after_red));
	}
	cout<<minchange;
}