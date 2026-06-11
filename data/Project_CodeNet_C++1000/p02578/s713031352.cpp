#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;

	vector<int> A(n);

	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	long long int sum=0;
	for(int i=1;i<n;i++){
		if(A[i]<A[i-1]){
			sum+=A[i-1]-A[i];
			A[i]=A[i-1];
		}

	}
	cout<<sum<<endl;
}
