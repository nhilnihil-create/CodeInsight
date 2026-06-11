#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int m,d,ret=0; cin>>m>>d;
	for (int i=1; i<=d; i++) {
		int x=i/10, y=i%10;
		if(x>=2&&y>=2&&x*y<=m)	
			ret++;
	}
	cout<<ret<<"\n";
	return 0;
}