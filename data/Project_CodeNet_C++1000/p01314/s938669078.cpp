#include <iostream>

using namespace std;

int main(){
	int a[1001];
	int n;
	for(int i=0;i<1001;i++){
		a[i]=i;
	}

	// for(int i=0;i<10;i++){
	// 	cout<<a[i]<<" ";
	// }

	while(cin>>n){
		
		if(n==0)break;
		int ans=0;
		for(int i=1;i<n;i++){
			int	now=0;
			for(int j=i;j<n;j++){
				// cout<<"n:"<<n<<endl;
				now+=a[j];
				// cout<<now<<endl;
				if(now>n)break;
				if(now==n){
					ans++;
					// cout<<"?¢???????"<<endl;
				
				}
				

			}

		}

		cout<<ans<<endl;

	}
	
}