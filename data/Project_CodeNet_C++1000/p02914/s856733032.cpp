#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxd=1e5+10;
ll p[maxd],a[maxd],sum,ans;
int t[maxd],tot,n;
void insert(ll x){
	for(int i=1;i<=tot;i++){
		if((x>>t[i])&1){
			if(p[i])x^=p[i];
			else{
				p[i]=x;
				break;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum^=a[i];
	}
	for(int i=60;i>=0;i--){
		if(((sum>>i)&1)==0){
			t[++tot]=i;
		}
	}
	for(int i=1;i<=n;i++){
		insert(a[i]);
	}
	for(int i=1;i<=tot;i++){
		if(((ans>>t[i])&1)==0)ans^=p[i];
	}
	cout<<(ans+(sum^ans))<<endl;
	return 0;
}