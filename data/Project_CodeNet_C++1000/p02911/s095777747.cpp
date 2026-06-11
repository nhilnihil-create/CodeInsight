#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>

typedef long long ll;
using namespace std;
const ll x=1000000007;
int mod(ll a){
	return a%x;
}
int main(){
	ll n,k,m;
	cin>>n>>k>>m;
	ll a[n],c[m];
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
	for(int i=0;i<m;i++){
		ll b;
		cin>>b;
		a[b]++;
	}
	for(int i=1;i<=n;i++){
		a[i]=k-m+a[i];
		if(a[i]>0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	
	
}