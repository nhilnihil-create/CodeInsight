#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
#include<utility>
#include<map>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
using Graph = vector<vector<int>>;
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll X,K,D;	cin>>X>>K>>D;
	ll M,P,c = abs(X)/D;
	if(K<c){
		if(X>=0) cout<<abs(X-K*D)<<endl;
		else	cout<<abs(X+K*D)<<endl;
		return 0;
	}
	if(X>=0){
		P=X-c*D;
		M=P-D;
		if((K-c)%2)	cout<<abs(M)<<endl;
		else cout<<abs(P)<<endl;
	}else{
		M=X+c*D;
		P=M+D;
		if((K-c)%2)	cout<<abs(P)<<endl;
		else cout<<abs(M)<<endl;
	}





    return 0;
}

