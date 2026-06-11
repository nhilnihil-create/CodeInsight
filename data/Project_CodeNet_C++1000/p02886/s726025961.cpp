#include <iostream>
using namespace std;
const int N=60;

int n;
int a[N];
int sum;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++){
			sum+=a[i]*a[j];	
		}
		
	cout<<sum;
	return 0;
}
