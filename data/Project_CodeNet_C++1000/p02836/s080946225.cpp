#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-i-1])sum++;
	}
	cout<<sum;
	return 0;
}