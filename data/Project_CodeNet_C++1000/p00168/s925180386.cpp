#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <cstring>
#include <string>


using namespace std;
typedef long long int ll;
typedef vector<int>  VI;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double PI  = acos(-1.0);
#define CLR(a) memset((a), 0 ,sizeof(a))

long int takakuwa[50];

int a(int i){
	if(i<0) return 0;
	return takakuwa[i];
}

void solve(){
	takakuwa[0] =1;
	REP(i,30){
		takakuwa[i+1] += takakuwa[i];
		takakuwa[i+2] += takakuwa[i];
		takakuwa[i+3] += takakuwa[i];
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	/*
	int n;
	cin >>n;
	for(int i;i<n;i++){
		cin >>;
	}
	*/

	solve();
	int n;
	while(cin >>n){
		if(n==0)return 0;
		cout << (takakuwa[n]-1)/(10*365) +1 <<endl;
		}	
	return 0;
}