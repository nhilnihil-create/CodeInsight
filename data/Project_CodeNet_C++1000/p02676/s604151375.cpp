#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i =a;i<b;i++)
using namespace std;
int main(){	
	int k;
	string s;
	cin>>k>>s;
	if(s.length()<=k)cout<<s<<"\n";
	else{
		l(i,0,k)
		cout<<s[i];
		cout<<"...\n";
	}
	
}