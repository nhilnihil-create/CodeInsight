#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int d[n];
	for(int i=0; i<n;i++){
		cin>>d[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				sum+=d[i]*d[j];
			}
		}
	}
	cout<<sum/2;
}