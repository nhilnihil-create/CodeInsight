#include<iostream>
using namespace std;
int main(){
	int n,m,p;
	while(cin>>n>>m>>p,n,m){
		int ans=0,d[n];
		double sum=0.0;
		for(int i=0;i<n;i++){
			cin>>d[i];
			sum+=d[i];
		}
		sum*=100;
		sum-=sum*(p*1.0/100);
		if(d[m-1]){
			ans=sum/d[m-1];
			cout<<ans<<endl;
		}
		else
		cout<<0<<endl;
	}
}