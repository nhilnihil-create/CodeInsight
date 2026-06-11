#include <iostream>


using namespace std;




int main(){
	

	int n;
	int a[5000];
	int max;
	int temp;
	
	while(cin>>n&&n){
	for(int i=0;i<n;i++)cin>>a[i];
	max=a[0];
	
	for(int i=0;i<n;i++){
		temp=0;
		for (int j=i; j<n; j++) {
			temp+=a[j];
		
		if (max<temp) {
			max=temp;
		}
		}
	}
	
	
	cout << max <<endl;
	}
		
	return 0;
}
 