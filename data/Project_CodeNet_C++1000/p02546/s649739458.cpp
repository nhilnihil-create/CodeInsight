#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAXN=2e5+100;
int main(){
	ios;
	string s;
	cin>>s;
	int len=s.size();
	if(s[len-1]=='s') s+="es";
	else s+="s";
	cout<<s<<'\n';
	return 0;
}