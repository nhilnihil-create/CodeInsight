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

int main(){
	ll k,n;
	cin>>k>>n;
	ll a[n]={0},maks=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			a[i]=k;
		}
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		maks=max(maks,abs(a[i]-a[i+1]));
	}
	maks=max(maks,abs(a[0]+k-a[n-1]));
	cout<<k-maks;
}

