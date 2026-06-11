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
int fak(int x){
	if(x<1){
		return 1;
	}
	else{
		return x*fak(x-1);
	}
}
int main(){
	int n;
	cin>>n;
	int a[n],c[n];
	ll ans1=0,ans2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c,c+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==c[j]){
				ans1+=(j*(fak(n-1-i)));
				c[j]=9;
				sort(c,c+n);
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c,c+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==c[j]){
				ans2+=(j*(fak(n-1-i)));
				c[j]=9;
				sort(c,c+n);
				break;
			}
		}
	}
	cout<<abs(ans1-ans2);
}

