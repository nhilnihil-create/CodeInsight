#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

#define MaxNum 260000
bool isprime[MaxNum];

void makeprime(){
	REP(i,MaxNum) isprime[i] = true;
	FOR(i,2,(int)sqrt(MaxNum)+1){
		FOR(j,i+1,MaxNum){
			if(j%i==0) isprime[j] = false;
		}
	}
}

int main(){
	ll int tmp;
	makeprime();
	while(cin>>tmp,tmp){
		ll int ans = 0;
		FOR(i,tmp+1,2*tmp+1){
			if(isprime[i]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}