#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll INF=1e10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> a(n);
	int Xor=0;
	for(int &i:a) cin>>i,Xor^=i;
	for(int i=0;i<n;i++) cout<<(a[i]^Xor)<<' ';
}
