#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long long LL;
const int modn=1e9+7;
const int maxn=2e5+10;
int a[maxn]={0};
char c[maxn];
int main(){
	int n;
	ll sum=1;
	ll num=0;
	scanf("%d",&n);
	scanf(" %s",c+1);
	for(int i=1;i<=n*2;i++){
		if(c[i]=='W'){
			if(num&1)num++;
			else {
				sum=sum*num%modn;
				num--;
			}
		}
		else {
			if(num&1){
				sum=sum*num%modn;
				num--;
			}
			else num++;
		}
	}
	if(num!=0){
		cout<<'0'<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++)sum=sum*i%modn;
	cout<<sum<<endl;
}