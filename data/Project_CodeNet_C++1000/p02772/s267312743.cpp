#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i++){
		if(arr[i]%2==0){
			if(arr[i]%3==0 || arr[i]%5==0) continue;
			else{
				cout<<"DENIED";
				return 0;
			}
		}	
	}
	cout<<"APPROVED";
}