#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define rep(i,n) for(i=0;i<(n);i++)

using namespace std;

int main() {
	int n,i,ans;
	
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		int a[n]={0};
		rep(i,n){
			cin>>a[i];
		}
		sort(a,a+n);
		ans=a[1]-a[0];
		
		for(int i=1;i<n-1;i++){
			if(ans>a[i+1]-a[i]){
				ans=a[i+1]-a[i];
			}
		}
		cout<<ans<<endl;
	}
	
	
	// your code goes here
	return 0;
}