#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int Maxn=505;
int n;
vector<vector<int> > L[Maxn],R[Maxn];
int ans[Maxn][Maxn];
void Go(int l,int r,int lvl){
	if (l==r) return;
	int mid=l+r>>1;
	Go(l,mid,lvl+1);
	Go(mid+1,r,lvl+1);
	vector<int> tmp;
	for (int i=l;i<=mid;i++) tmp.pb(i);
	L[lvl].pb(tmp);
	tmp.clear();
	for (int i=mid+1;i<=r;i++) tmp.pb(i);
	R[lvl].pb(tmp);
}
int main(){
	scanf("%d",&n);
	Go(1,n,1);
	for (int i=1;i<=Maxn;i++){
		if (L[i].empty()) break;
		for (int j=0;j<L[i].size();j++){
			vector<int> &l=L[i][j],&r=R[i][j];
			for (auto u:l){
				for (auto v:r){
					ans[u][v]=i;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			printf("%d ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}