#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int lli;
const long long int MaxN=200004;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	bool posible[MaxN];
	void solve(){
		lli N,i,j;
		cin>>N;
		posible[100]=1;
		posible[101]=1;
		posible[102]=1;
		posible[103]=1;
		posible[104]=1;
		posible[105]=1;
		for(i=106;i<=N;i++){
			posible[i]|=posible[i-100];
			posible[i]|=posible[i-101];
			posible[i]|=posible[i-102];
			posible[i]|=posible[i-103];
			posible[i]|=posible[i-104];
			posible[i]|=posible[i-105];
		}		
		cout<<posible[N];
	}
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,j,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}
