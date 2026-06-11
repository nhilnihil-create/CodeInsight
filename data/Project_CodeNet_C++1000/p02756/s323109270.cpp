#include <bits/stdc++.h>
#define N 500006
using namespace std;
int l=200001,r,q,t,f,c;
char p[N];
string s;
bool flag;
int main(){
	cin>>s;
	for(int i=200001;i<=s.size()+200000;i++)p[i]=s[i-200001];
	r=s.size()+200000;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>t;
		if(t==1)flag^=1;
		else{
			cin>>f;
			if(f==1){
				if(flag)cin>>p[++r];
				else cin>>p[--l];
			}else{
				if(flag)cin>>p[--l];
				else cin>>p[++r];
			}
		}
	}
	if(flag)for(int i=r;i>=l;i--)cout<<p[i];
	else for(int i=l;i<=r;i++)cout<<p[i];
	cout<<endl;
	return 0;
}