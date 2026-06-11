#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip> 
#include <cstring>
#include <queue>
#include <stack> 
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
ll n; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll res = 2,t;
	if(n == 2){
		res = 1;
	}else{
		for(ll i = 2;i <= sqrt(n);i++){
			t = n;
			while(t >= i){
				if(t % i == 0){
					t /= i;
				}else{
					t %= i;
				}
			}
			if(t == 1){
				res++;
			}
			if((n - 1) % i == 0 && i != sqrt(n - 1)){
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}