#include<bits/stdc++.h>
using namespace std;

int main(){
	int h1,m1,h2,m2;
	int k;
	cin>>h1>>m1>>h2>>m2;
	cin>>k;
	
	h1=h1*60+m1;
	h2=h2*60+m2;
	int ans=abs(h1-h2);
	ans = ans-k;
	cout<<ans;
}