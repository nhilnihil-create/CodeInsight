#include <bits/stdc++.h>

using namespace std;

int a[505][505];

void solve(int l, int r, int c){
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,c+1);
	solve(mid+1,r,c+1);
	for(int i=l;i<=mid;i++){
		for(int j=mid+1;j<=r;j++){
			a[i][j]=c;
		}
	}
}

int main(){
	int n; cin >> n;
	solve(0,n-1,1);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}