#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m; cin>>n>>m;
	bool ok = false;
	for(int i=1; i<=1250 && !ok; i++){
		int p1 = (i*8)/100;
		int p2 = i/10;
		if(p1 == n && p2 == m ){
			ok=1;
			cout<<i<<'\n';
		}
	}
	if(ok==0)cout<<-1<<endl;
}
