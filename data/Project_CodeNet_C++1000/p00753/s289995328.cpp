#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		int ans=0;
		for(int i=n+1;i<=2*n;i++){
			int f=0;
			for(int j=2;j*j<=i;j++){
				if(i%j==0){
					f=1;
					break;
				}
			}
			if(f==0 && i!=1)
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}