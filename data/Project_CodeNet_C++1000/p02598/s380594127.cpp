#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;
int n,k,a[maxn],maxl=0;

int query(int l,int r){
	if (r<=l) return l;
	int mid = (l+r)>>1;
	int ans = 0;
	for (int i=1;i<=n;i++){
		ans += ((a[i]-1)/mid); 
	}
	if (ans <= k) return query(l,mid);
	else return query(mid+1,r);
}

int main(){
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];	
		maxl = max (maxl,a[i]);
	}
	cout << query(1,maxl);
	return 0;
}	