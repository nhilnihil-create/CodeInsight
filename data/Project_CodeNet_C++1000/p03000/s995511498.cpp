#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const long long int MaxN=10000005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	lli N,X,i,sum=0,p;
	cin>>N>>X;
	for(i=1;i<=N;i++){
		cin>>p;
		sum+=p;
		if(sum>X){
			cout<<i;
			return 0;
		}
	}
	cout<<N+1;
}