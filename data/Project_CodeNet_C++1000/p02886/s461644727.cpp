#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    long long sum = 0;
    for(int i=0; i<n; i++){
    	for(int j=i+1; j<n; j++) sum+=arr[i]*arr[j];
	}
	cout<<sum;
}