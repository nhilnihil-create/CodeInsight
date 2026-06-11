#include<iostream>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],b[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i==1)
		    cout<<b[i];
		else
			cout<<" "<<b[i];
	}
	return 0;
}
