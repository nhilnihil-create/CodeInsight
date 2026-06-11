#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=300005;
int tree[4*MAXN],kiri[MAXN],kanan[MAXN];
pii a[MAXN];

int query(int now,int L,int R,int x,int y){
	if(L>=x && R<=y)return tree[now];
	if(L>y || R<x)return 0;
	int mid=(L+R)/2;
	return max(query(2*now,L,mid,x,y),query(2*now+1,mid+1,R,x,y));
}

void update(int now,int L,int R,int pos,int val){
	if(L==R){
		tree[now]+=val;
		return;
	}
	int mid=(L+R)/2;
	if(pos<=mid)update(2*now,L,mid,pos,val);
	else update(2*now+1,mid+1,R,pos,val);
	tree[now]=max(tree[2*now],tree[2*now+1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++){
		if(kiri[a[i].first]==0)kiri[a[i].first]=i;
		kanan[a[i].first]=i;
	}
	for(int i=1;i<=k;i++)update(1,1,m,a[i].second,1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(kiri[i]==0)continue;
		for(int j=kiri[i];j<=kanan[i];j++)update(1,1,m,a[j].second,-1);
		ans=max(ans,kanan[i]-kiri[i]+1+query(1,1,m,1,m));
		for(int j=kiri[i];j<=kanan[i];j++)update(1,1,m,a[j].second,1);
	}
	cout << ans << '\n';
	return 0;
}

