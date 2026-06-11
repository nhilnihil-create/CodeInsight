#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,A[110];
	cin>>N;
	string ans="APPROVED";
	for(int i=0;i<N;i++){
		cin>>A[i];
		if(A[i]%2==0){
			if(A[i]%3!=0&&A[i]%5!=0)
			ans="DENIED";
		}
	}
	cout<<ans;  
	return 0;
 } 