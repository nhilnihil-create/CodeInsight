#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	int cnt=1;
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1])
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}