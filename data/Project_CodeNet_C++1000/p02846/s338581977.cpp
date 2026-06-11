#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	
	int t1,t2;
	cin >> t1 >> t2;
	ll a1,a2;
	cin >> a1 >> a2;
	ll b1,b2;
	cin >> b1 >> b2;
	
	ll dist1 = (a1-b1)*t1; // not 0
	ll dist2 = (a2-b2)*t2; // not 0
	
	if(dist1 + dist2 == 0){
		cout << "infinity" << endl;
		return 0;
	}
	
	if(dist1>0){
		dist1 *= -1;
		dist2 *= -1;
	}
	
	if(dist1 + dist2 < 0){
		cout << 0 << endl;
		return 0;
	}
	
	
	ll amari = -dist1%(dist1+dist2);
	if(amari == 0){
		cout << -dist1/(dist1+dist2) * 2 << endl;
	}
	else{
		cout << -dist1/(dist1+dist2) * 2 + 1<< endl;
	}
	
	return 0;
}