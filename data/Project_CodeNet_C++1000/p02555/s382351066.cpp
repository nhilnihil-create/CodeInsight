#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int N=2e3+10;
int a[N]={0,0,0,1};
int main(){
	int n;
	cin>>n;
	for(int i=4;i<=n;i++)a[i]=(a[i-1]+a[i-3])%Mod;
	cout<<a[n]<<endl;
	return 0;
}