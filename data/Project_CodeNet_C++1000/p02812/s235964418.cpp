#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){	
	ll n;
	string s;
	cin>>n;
	cin>>s;
	ll i=0,cont=0;
	string tar = "ABC";
	while(s[i]){
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') cont++;
		i++;
	}
	cout<<cont<<"\n";
}