#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s;
	cin>>s;

	int n=s.size();
	int sum =0;
	for(int i=0;i<n;i++){
		sum+=(s[i]-'0');
	}

	if(sum%9)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;   	 
}