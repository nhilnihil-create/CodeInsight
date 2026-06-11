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
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=n-2;i++){
		if(a[i]==b[i]){
			if(a[i+1]==b[i+1] && a[i+2]==b[i+2]){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<'\n';
	return 0;
}