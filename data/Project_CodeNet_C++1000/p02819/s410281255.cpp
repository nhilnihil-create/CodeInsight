#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int arr[200000];
	memset(arr,0,sizeof(arr));
	for(long long int i=2;i*i<200000;i++){
		for(long long int j=(i*i);j<200000;j+=i){
			if(arr[j]==0){
				arr[j]=1;
			}
		}
	}
	long long int n;
	cin>>n;
	for(long long int i=n;i<200000;i++){
		if(arr[i]==0){
			cout<<i;
			break;
		}
	}
	return 0;
}