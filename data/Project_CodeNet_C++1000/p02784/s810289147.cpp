#include<bits/stdc++.h>
using namespace std;


int main(){
	int  h,n,d;
	cin>>h>>n;
	int a[n];
	for(int i = 0; i<n ;i++){	
		cin>>d;
		a[i]=d;
		h=h-a[i];

	}

	
	if(h>0){
			cout<<"No";
			}
	else{
		cout<<"Yes";
		}
						
return 0 ;
}