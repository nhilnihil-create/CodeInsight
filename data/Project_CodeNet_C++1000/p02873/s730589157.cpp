#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,f[500005];
long long sum;
string st;
int main(){
	cin>>st;n=st.size();
	rep(i,n){
		if(st[i-1]=='<') f[i]=max(f[i],f[i-1]+1);
	}
	rep(i,n){
		if(st[n-i]=='>') f[n-i]=max(f[n-i],f[n-i+1]+1);
	}
	rep(i,n+1){
		sum+=f[i-1];
	}cout<<sum<<endl;
	return 0;
}