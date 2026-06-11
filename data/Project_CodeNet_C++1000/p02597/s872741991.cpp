#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
char a[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	if(a[i]=='W')cnt++;
	int res=0;
	for(int i=n-cnt+1;i<=n;i++){
		if(a[i]!='W')res++;
	}
	cout<<res<<endl;
}

