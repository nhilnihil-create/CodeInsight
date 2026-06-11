//abc174_e.cpp
//Sat Sep 12 10:55:08 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n,k;
	cin >> n >> k;

	ll a[n];
	rep(i,n){
		cin >> a[i];
	}

	sort(a,a+n,greater<ll>());

	if (k==0){
		cout << a[0] << endl;
		return 0;
	}

	ll ok = 1e9+1;
	ll ng = 0;
	while(abs(ok-ng)>1){
		ll mid = (ok+ng)/2;
		ll tmp = 0;
		int flag = 1;
		rep(i,n){
			if (a[i]>mid){
				ll cut = a[i]/mid;
				cut++;
				while(cut*mid>=a[i]){
					cut--;
				}
				// cout << a[i] << " " << mid << " " << cut << endl;
				tmp+=cut;
			}
			if (tmp>k){
				flag = 0;
				break;
			}
		}
		if(flag){
			ok = mid;
		}else {
			ng = mid;
		}
	}

	cout << ok << endl;
//	printf("%.4f\n",ans);
}