#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#define ll long long
#define chushi(a, b) memset(a, b, sizeof(a))
const double eps = 1e-8;
const ll INF = 1e18 + 5;
const ll mod = 998244353;
const int maxn = 1e5+5;
using namespace std;

int n, m, x;
int book[20][20] = {0};
int val[20] = {0};
ll tot = INF;

void solve(){
	ll len = 1 << n;
	for(int i = 0; i <= len; i++){
		chushi(val, 0);
		int ind = i; ll sum = 0;
		for(int j = 1; j <= n; j++, ind >>= 1){
			if(ind & 1){
				sum += book[j][0];
				for(int k = 1; k <= m; k++){
					val[k] += book[j][k];
				}
			}
		}
		int flag = 0;
		for(int j = 1; j <= m; j++){
			if(val[j] < x) flag = 1; 
		}
		if(flag) continue;
		tot = min(tot, sum);
	}
}

int main(){
	
	cin >> n >> m >> x;
	for(int i = 1; i <= n; i++){
		cin >> book[i][0];
		for(int j = 1; j <= m; j++){
			cin >> book[i][j];
		}
	}
    
    solve();
    
    if(tot == INF) cout << -1 << endl;
    else cout << tot << endl;
    
    return 0;
}



