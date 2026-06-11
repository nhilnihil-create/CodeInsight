#include <bits/stdc++.h>
using namespace std;
int vc[1000005];
int v2[1000005], a[1000005], b[1000005];
int main(){
	int n;
	string s;
	cin>>n>>s;
	memset(v2, 0, sizeof v2);
	for(int i=1;i<=1000000;i++){
		int x=i;
		while(x%2==0){
			x/=2;
			v2[i]++;
		}
	}
	vc[0]=0;
	for(int i=1;i<n;i++){
		vc[i]=vc[i-1]+v2[n-i]-v2[i];
	}
	bool bb=false;
	for(int i=0;i<n;i++){
		a[i]=(int)(s[i]-'1');
		b[i]=a[i]/2;
		if(a[i]==1) bb=true;
	}
	int m2=0;
	for(int i=0;i<n;i++){
		if(a[i]==1 && vc[i]==0){
			m2^=1;
		}
	}
	if(m2==1){
		cout<<1;
		return 0;
	}
	if(bb){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(b[i]==1 && vc[i]==0) m2^=1;
	}
	cout<<2*m2;

}