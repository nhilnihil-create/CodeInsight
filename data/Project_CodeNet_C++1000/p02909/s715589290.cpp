#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string s;
	cin>>s;
	map<string,string> m;
	m["Sunny"]="Cloudy";
	m["Cloudy"]="Rainy";
	m["Rainy"]="Sunny";
	cout<<m[s]<<endl;
	return 0;
}
