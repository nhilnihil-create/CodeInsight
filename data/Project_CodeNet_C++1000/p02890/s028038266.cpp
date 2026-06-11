#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[300005],cnt[300005];
ll rui[300005],num[300005];
int main(){
	scanf("%d",&n);
	rep(i,n){ scanf("%d",&a[i]); cnt[a[i]]++; }
	rep(i,300005){
		rui[cnt[i]]+=cnt[i];
		num[cnt[i]]++;
	}
	for(int i=1;i<=300004;i++){
		rui[i] += rui[i-1];
		num[i] += num[i-1];
	}
	repn(k,n){
		int lb = 0, ub = n/k+1;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			ll sum = rui[mid] + (num[300004]-num[mid]) * mid;
			if(sum >= mid * k) lb = mid;
			else ub = mid;
		}
		printf("%d\n",lb);
	}
}