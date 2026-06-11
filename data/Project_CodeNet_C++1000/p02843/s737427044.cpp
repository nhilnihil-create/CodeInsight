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
	ll x;
	cin>>x;
	ll y=((x%100)+4)/5;
	x/=100;
	if(x>=y){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
}