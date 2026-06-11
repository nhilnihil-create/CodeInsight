#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
ll a[maxn],s[maxn],c[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=1,tmp;i<=n;i++) {
	  cin>>tmp;
	  c[tmp]++;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			a[++tot]=c[i];
		}
	}
	sort(a+1,a+tot+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
	 ll l=0,r=n;
	 while(l<=r){
	 	ll mid=l+r>>1;
		ll pos=upper_bound(a+1,a+1+tot,mid)-a;
		pos--;
		if(s[pos]+(tot-pos)*mid<mid*i)
		 r=mid-1;
		else l=mid+1;
	}
	cout<<r<<'\n';
 }
}