#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
char str[N],st[N];
signed main(){
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	cin>>(str+1);
	int len=strlen(str+1);
	int sum=0;
	int F=0;
	for(int i=b-1;i<=d+1;i++){
		if(str[i]=='.') sum++;
		else sum=0;
	//	cout<<sum<<'\n';
		if(sum>=3){
			F=1;
			break;
		}
	}
//	cout<<F<<'\n';
	int add=0;
	for(int i=a+1;i<=c;i++){
		if(str[i]=='#') add++;
		else add=0;
		if(add>1){
			cout<<"No";
			return 0;
		}
	}
	add=0;
	for(int i=b+1;i<=d;i++){
		if(str[i]=='#') add++;
		else add=0;
		if(add>1){
			cout<<"No";
			return 0;
		}
	}
	if(d>c){
		cout<<"Yes";return 0;
	}
	str[d]='#';
	add=0;
	int f=1;
	for(int i=a+1;i<=c;i++){
		if(str[i]=='#') add++;
		else add=0;
		if(add>1){
			f=0;break;
		}
	}
	if(f){
		cout<<"Yes";
	}else if(!f&&F){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}