#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int gcd(int a,int b){
	if(a==0)
	return b;
	if(b==0)
	return a;
	if(a==b)
	return a;
	if(a>b)
	return gcd(a-b,b);
	return gcd(a,b-a);
}

int GCD(int a,int b){
	if(a==0)
	return b;
	if(b==0)
	return a;
	if(a==b)
	return a;
	return GCD(b,a%b);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	vector<int>v;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	int x=n/2;
	sort(v.begin(),v.end());
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]!=v[i])
		cnt++;
	}
	if(x>=cnt)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
}