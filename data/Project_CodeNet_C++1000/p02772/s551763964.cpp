#include<iostream>
using namespace std;
int main()
{
	int n,a[250000];
	int ans=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==0){
			ans++;
			if(a[i]%3==0||a[i]%5==0){
				s++;
			}
		}
	}
	if(ans==s){
		cout<<"APPROVED"<<endl;
		return 0;
	}
	cout<<"DENIED"<<endl;
	return 0;
}