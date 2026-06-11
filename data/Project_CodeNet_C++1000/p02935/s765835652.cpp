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
	int n;
	cin>>n;
	float a[n],ans;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=(a[0]+a[1])/2;
	for(int i=2;i<n;i++){
		ans=(ans+a[i])/2;
	}
	cout<<ans;
}

