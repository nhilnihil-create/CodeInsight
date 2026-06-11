#include <bits/stdc++.h>
using namespace std;

int n,k,q,dude,a[100001],b[100001];

int main(){
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		a[i]=k;
	}
	for(int i=1;i<=q;i++){
		cin>>dude;
		b[dude]++;
	}
	for(int i=1;i<=n;i++){
		if((a[i]+b[i]-q)>0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}
