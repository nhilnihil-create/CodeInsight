#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
map<string,int> m;
int main(){
	m["MON"]=1;m["TUE"]=2;m["WED"]=3;m["THU"]=4;m["FRI"]=5;m["SAT"]=6;m["SUN"]=7;
	string s; cin>>s;
	if(s=="SUN") cout<<7;
	else cout<<(7-m[s]);

}
