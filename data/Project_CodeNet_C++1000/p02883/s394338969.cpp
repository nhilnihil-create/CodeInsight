#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
vector<ll> a;
vector<ll> f;
ll n,k;
//A1*Fi1-a1*Fi1,A2*Fi2-a2*Fi2,An*Fin-an*Fin
bool check(ll mid){//最大値をmidに出来るか.
	//各aiの要素はmid/Fi以下であるべき.
	ll cost = 0;
	for(int i = 0;i < n;i++){
		ll aa = mid / f[i];
		if(aa < a[i])cost += a[i] - aa;
	}

	if(cost <= k)return true;
	else return false;
}


int main(){
	cin >> n >> k;
	a.resize(n);
	f.resize(n);

	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		cin >> f[i];
	}

	sort(a.begin(),a.end(),greater<ll>());
	sort(f.begin(),f.end());

	ll ok = 1e18;
	ll ng = -1;
	while(ok - ng > 1){
		ll mid = (ok + ng) / 2;
		if(check(mid)){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}

	cout << ok << endl;
}
