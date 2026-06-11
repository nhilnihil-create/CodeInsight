#include <bits/stdc++.h>

using namespace std;




int main(){
	int n,l,i;
	cin>>n>>l;
	int arr[n],m=INT_MAX,totalsum(0),choosedapple(0);
	for(i=0;i<n;i++){
		arr[i]=l+i;
		totalsum+=arr[i];
		if(abs(arr[i])<m){
			m=abs(arr[i]);
			choosedapple=arr[i];
		}
	}
	cout<<totalsum-choosedapple;

    return 0;
}
