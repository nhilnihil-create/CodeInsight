#include <iostream>
using namespace std;
#define ll long long

int main(){
	int h,n;
	cin>>h>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		sum+=t;
		if(sum>=h) {
			cout<<"Yes";
			return 0;
		}
	}	
	cout<<"No";
	return 0;
}