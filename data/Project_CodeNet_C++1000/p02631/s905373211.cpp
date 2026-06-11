#include <iostream>
using namespace std;
typedef long long LL;
int a[200010];	
int main(){
	int n;
	LL sum=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum=sum^a[i];
	}
	for(int i=1;i<=n;++i)
	{
		cout<<(sum^a[i])<<" ";
	}
	
	return 0;
}