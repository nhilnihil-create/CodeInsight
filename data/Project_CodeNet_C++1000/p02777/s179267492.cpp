#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	int n1,n2;
	cin>>n1>>n2;
	map<string,int>m;
	m[a] = n1;
	m[b] = n2;
	string s;
	cin>>s;
	m[s]--;
	cout<<m[a]<<" "<<m[b];
}