#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	for(int i=0; s[i]; i++){
		int num = (int)(s[i]-'A');
		num+=n;
		num%=26;
		s[i] = (char)(num+'A');
	}
	cout<<s;
}