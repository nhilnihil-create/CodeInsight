#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	long long n,k,s;
	cin >> n >> k >> s;
	long long replace=s-1;
	if(replace<=0)replace=s+1;
	vector<long long> result(n,replace);
	int cnt=0;
	for(int i=0;i<n;i++){
		if(cnt!=k){
			result[i]=s;
			cnt++;
		}
	}
	
	for(int i=0;i<n;i++){
		cout << result[i] << " ";
	}
	cout << endl;
	
	return 0;
}
