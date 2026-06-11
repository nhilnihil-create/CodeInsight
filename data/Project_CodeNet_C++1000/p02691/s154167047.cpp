#include<iostream> 
#include <cassert>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
map<int,int>cnt;
long long ans;
int a[312345];

int main() {
	cin >> n;


	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans+=cnt[a[i]-i];
		cnt[-i-a[i]]++;
	}
	cout<<ans;
	return 0; 
}

