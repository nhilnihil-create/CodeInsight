#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a,b,c,d,mi=100000000;
	cin>>a>>b>>c;
	vector<int>va(a);
	vector<int>vb(b);
	int x,y;
	int mia=100000000,mib=100000000;
	for(int i=0;i<a;i++){
		cin>>va[i];
		mia=min(mia,va[i]);
	}
	for(int i=0;i<b;i++){
		cin>>vb[i];
		mib=min(mib,vb[i]);
	}
	mi=mia+mib;
	for(int i=0;i<c;i++) {
		cin>>x>>y>>d;
		if(va[x-1]+vb[y-1]-d<mi){
			mi=min(mi,va[x-1]+vb[y-1]-d);
		}
	}
	cout<<mi<<endl;
	return 0;
}
