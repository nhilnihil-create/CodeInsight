#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int countWhite = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'R'){
	countWhite++;
}
}
int there = 0;
for(int i=0;i<countWhite;i++){
	if(s[i]=='R')
		there++;
}
cout<<countWhite - there;
	return 0;
}

