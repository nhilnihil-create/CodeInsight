#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	
		cin>>a[i];
	}

	int s=1000000000;
	for(int i=0;i<100;i++){
	
		int temp=0;

		for(int j=0;j<n;j++){

			temp+=pow(a[j]-i,2);
		}
		if(temp<s){
		
			s=temp;
		}
	}
	cout<<s<<"\n";
	return 0;
}
