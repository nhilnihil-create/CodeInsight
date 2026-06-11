#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};
lld arr[222];
lld base[61];
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(base,0,sizeof(base));
		int n;
		scanf("%d",&n);
		for(int e=0;e<n;e++) scanf("%lld",&arr[e]);
		string s;
		cin >> s;
		int err = 0;
		for(int e=n-1;e>=0;e--){
			if(s[e]=='1'){
				for(int p=60;p>=0;p--){
					if(arr[e]&(1ll<<p)){
						arr[e] ^= base[p];
					}
				}
				if(arr[e]) err = 1;
			}else{
				for(int p=60;p>=0;p--){
					if(arr[e]&(1ll<<p)){
						if(base[p]==0) base[p] = arr[e];
						arr[e] ^= base[p]; 
					}
				}
			}
		}
		printf("%d\n",err);
	}
	return 0;
}
