#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 0;i<n;i++)
#define ll long long


int main(){

	ll n;
	cin>>n;
	ll key = 1;
	ll sum = 0;
	while(n>0){
		if(key%3!=0 && key%5!=0 && key%15!=0){
			// cout<<"KEY "<<key<<endl;
			sum = sum + key;
		}
		n--;
		key++;
	}

	cout<<sum;

}