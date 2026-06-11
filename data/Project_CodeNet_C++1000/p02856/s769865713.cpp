#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll M;
	cin >> M;
	ll temp = 0;
	ll digit = 0;
	rep(i,M){
		ll d,c;
		cin >> d >> c;
		temp += d*c;
		digit += c;
	}
	
	cout << (temp-1)/9 + digit - 1 << endl;
    return 0;
}

