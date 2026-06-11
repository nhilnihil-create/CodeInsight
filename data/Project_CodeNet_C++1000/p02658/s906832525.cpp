#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll; // 10^19



int main(void){
    int n;
    cin >> n;
    vector <ll> x(100000);
    REP(i,n)
        cin >> x[i];
    REP(i,n){
		if(x[i]==0){
			cout<<0;
			return 0;
		}
	}
    ll t=1;
	REP(i,n){
		if(1000000000000000000/t<x[i]){
			cout<<-1;
			return 0;
		}
		t*=x[i];
	}
	cout<<t;
    return 0;
}