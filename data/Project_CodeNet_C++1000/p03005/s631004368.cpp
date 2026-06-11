#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	if(k==1) cout<<0<<"\n";
	else cout<<abs(n-(k-1)-1)<<"\n";
	return 0;
}