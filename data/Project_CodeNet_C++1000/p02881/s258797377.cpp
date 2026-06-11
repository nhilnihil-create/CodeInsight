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
	ll n,a,b;
	cin>>n;
	for(int i=pow(n,0.5);i>=1;i--){
		if(n%i==0){
			a=i;
			b=n/i;
			break;
		}
	}
	cout<<(a-1)+(b-1);
}