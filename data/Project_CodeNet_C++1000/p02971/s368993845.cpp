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
	ll n;
	cin>>n;
	ll a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n,greater<int>());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]!=b[j]){
				cout<<b[j]<<endl;
				break;
			}
			else{
				cout<<b[j+1]<<endl;
				break;
			}
		}
	}
}