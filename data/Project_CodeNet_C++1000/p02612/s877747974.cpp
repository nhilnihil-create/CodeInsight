#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int k=n%1000;
	if(k==0)cout<<0<<endl;
	else cout<<1000-k<<endl;
} 