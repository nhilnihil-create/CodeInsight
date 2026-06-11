#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAXN=2e5+100;
int a[110],b[110];
int main(){
	ios;
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;(n-1)>=i;i++){
		sum+=(n-1)/i;
	}
	cout<<sum<<'\n';	
	return 0;
}