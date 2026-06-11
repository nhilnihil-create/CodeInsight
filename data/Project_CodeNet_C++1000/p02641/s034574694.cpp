#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	
	
	int n,k;
	cin>>n>>k;
	int ar[k];
	map<int,int> m1;
	for(int i=0;i<k;i++){
		cin>>ar[i];
		m1[ar[i]]++;
	}
	for(int i=0;i<=100;i++){
		int l = n-i;
		int r = n+i;
		if(!m1[l]){
			cout<<l<<"\n";
			break;
		}else if(!m1[r]){
			cout<<r<<"\n";
			break;
		}
	}						
	return 0;
}