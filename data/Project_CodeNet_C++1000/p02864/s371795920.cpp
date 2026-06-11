/*
Problem : https://atcoder.jp/contests/abc145/tasks/abc145_f
Algorithm : dp + BIT
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

const ll INF = 1e18;
const int MAXN = 305;

int n,k;
int id[MAXN];
ll a[MAXN],f[MAXN][MAXN],b[MAXN];

bool cmp(const int &x,const int &y){
	return a[x] < a[y];
}

class BIT2{
	private:
		ll c[MAXN];
		
		int lowbit(int x){
			return x & -x;
		}
	public:
		BIT2(){
			for(int i = 0;i < MAXN;i++)
			    c[i] = INF;
		}
		
		ll Query(int x){
			ll res = INF;
			while(x >= 1){
				res = min(res,c[x]);
				x -= lowbit(x);
			}
			return res;
		}
		
		void Add(int x,ll val){
			while(x <= n){
				c[x] = min(c[x],val);
				x += lowbit(x);
			}
		}
		
		void print(){
			for(int i = 1;i <= n;i++)
			    printf("%lld ",c[i]);
			printf("\n");
		}
} bit2[MAXN];

class BIT1{
	private:
		ll c[MAXN];
		
		int lowbit(int x){
			return x & -x;
		}
	public:		
		BIT1(){
			for(int i = 0;i < MAXN;i++)
			    c[i] = INF;
		}
		
		ll Query(int x){
			ll res = INF;
			while(x <= n){
				res = min(res,c[x]);
				x += lowbit(x);
			}
			return res;
		}
		
		void Add(int x,ll val){
			while(x >= 1){
				c[x] = min(c[x],val);
				x -= lowbit(x);
			}
		}
		
		void print(){
			for(int i = 1;i <= n;i++)
			    printf("%lld ",c[i]);
			printf("\n");
		}
} bit1[MAXN];

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++)
		    f[i][j] = INF;
	}
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		b[i] = a[i];
	}
	sort(b + 1,b + 1 + n);
	int m = unique(b + 1,b + 1 + n) - b - 1;
	for(int i = 1;i <= n;i++){
		f[i][0] = 0;
		f[i][1] = a[i];
		id[i] = lower_bound(b + 1,b + 1 + n,a[i]) - b;
	}
	for(int j = 2;j <= n - k;j++){
//		printf("%d : \n",j);
		for(int i = 1;i < j;i++){
			bit1[j - 1].Add(id[i],f[i][j - 1]);
			bit2[j - 1].Add(id[i],f[i][j - 1] - a[i]);
//			bit1[j - 1].print();
//			bit2[j - 1].print();
//			printf("\n");
		}
		for(int i = j;i <= n;i++){
			f[i][j] = min(f[i][j],bit1[j - 1].Query(id[i]));
			f[i][j] = min(f[i][j],bit2[j - 1].Query(id[i] - 1) + a[i]);
			bit1[j - 1].Add(id[i],f[i][j - 1]);
			bit2[j - 1].Add(id[i],f[i][j - 1] - a[i]);			
//			bit1[j - 1].print();
//			bit2[j - 1].print();
//			printf("\n");
		}
//		printf("\n");
	}
	ll ans = INF;
	for(int i = 1;i <= n;i++)
	    ans = min(ans,f[i][n - k]);
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j <= n;j++)
//		    printf("%lld ",f[i][j]);
//		printf("\n");
//	}
	printf("%lld\n",ans);
	return 0;
}
/*f[i][j] = min(f[i][j],f[l][j - 1] + max(0,a[i] - a[l])
  a[i] > a[l] --> f[l][j - 1] - a[l] + a[i]
  a[i] <= a[l] --> f[l][j - 1]
*/