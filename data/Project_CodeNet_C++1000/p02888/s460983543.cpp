#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
	int n;
	cin>>n;
	int ans={};
	int l[n]={};
	for(int i=0; i<n; i++){
		cin>>l[i];
	}
	sort(l,l+n);
	//for(int i=0; i<n; i++){
	//	cout<<l[i]<<" ";
	//}cout<<endl;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int a=l[i]+l[j];
			//cout<<i<<" "<<j<<endl;
			//cout<<a<<endl;
			int k=distance(l,lower_bound(l,l+n,a))-1;
			//cout<<"K"<<k<<endl;
			ans+=k-j;
			
		}
	}
	cout<<ans<<endl;
}