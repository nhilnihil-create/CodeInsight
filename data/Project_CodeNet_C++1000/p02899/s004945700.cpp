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
	ll n;
	cin>>n;
	ll a[n],b[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<' ';
	}
}

