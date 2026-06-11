//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	cin>>s;
	
	int ans = 0;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i] != s[n-i-1])ans++;
	}
	cout<<ans/2;
	return 0;
}
