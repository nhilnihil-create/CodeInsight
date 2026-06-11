/*
Problem : https://atcoder.jp/contests/agc041/tasks/agc041_b
Algorithm : binary search
Status :
*/
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int n;
ll m,p,v;
ll a[MAXN];

bool check(int x){
	ll cnt = (v - (p - 1)) * m;
	if(a[p] > a[x] + m)
		return false;
	for(int i = 1;i <= n;i++){
		if(a[i] <= a[x])
			cnt -= m;
	}
	for(int i = x;i >= p;i--){
		if(a[x] == a[i])
			continue;
		cnt -= (a[x] + m - a[i]);
	}
	if(cnt <= 0)
		return true;
	return false;
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	scanf("%d%lld%lld%lld",&n,&m,&v,&p);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n,greater<ll>());
	int l = 1,r = n,ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else
			r = mid - 1;
	}
	printf("%d\n",ans);
	return 0;
}
