#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	vector<long long int> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long int m=1000,st=0;
	for(int i=0;i<n;i++){
		if((i<n-1)&&a[i+1]<=a[i]){
			m+=st*a[i];
			st=0;
		}
		if((i<n-1)&&a[i+1]>a[i]){
			st+=m/a[i];
			m-=(m/a[i])*a[i];
		}
		if(i==n-1){
			m+=st*a[i];
		}
	}
	cout<<m<<endl;
}