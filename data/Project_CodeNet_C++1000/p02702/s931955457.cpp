#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long int lli;
const long long int MaxN=200005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli pre[MaxN],pot[MaxN];
	void solve(){
		lli N,i,j,l,r,numero,res=0;
		string numb;
		cin>>numb;
		N=numb.size();
		numero=0;
		pot[0]=1;
		pre[0]=1;
		for(i=1;i<=N;i++){
			pot[i]=pot[i-1]*10;
			pot[i]=pot[i]%2019;
		}
		for(i=0;i<N;i++){
			numero=numero+(pot[N-i-1]*(numb[i]-'0'));
			numero=numero%2019;
			res+=pre[numero];
			pre[numero]+=1;
			//cout<<numero<<" ";
		}
		cout<<res;
	}
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}