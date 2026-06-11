//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	int len = s.size();
	for(int i=0;i<len;i++){
		int x = s[i] - 'A';
		x += n;
		x%=26;
		s[i] = s1[x];
	}

	cout<<s<<endl;

	return 0;
}