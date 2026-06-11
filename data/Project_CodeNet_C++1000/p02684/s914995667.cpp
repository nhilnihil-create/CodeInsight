#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;

using namespace std;

int main(){
	
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	a[0] = 1;
	
	vector<int> table(n + 1 , -1);
	vector<int> memo;
	int now = 0;
	
	while(table[a[now]] == -1){
		memo.push_back(a[now]);
		table[a[now]] = memo.size();
		now = a[now];
	}

	int cycle = memo.size() + 1 - table[a[now]];
	int before_cycle = table[a[now]] - 1;
	
	if(k <= before_cycle){
		cout << memo[k] << endl;
	}else{
		cout << memo[before_cycle + ((k - before_cycle) % cycle)] << endl;
	}
	
	return 0;
}
 