#include <bits/stdc++.h>
using namespace std;
int main() {
	double n,m,s;
	while(cin>>n>>m>>s,n){
		int ans=0;
		n+=100;
		m+=100;
		for(int i=1;i<1000;i++){
			for(int j=1;j<1000;j++){
				int p1=i*n/100;
				int p2=j*n/100;
				if(p1+p2==s){
					int p1=i*m/100;
					int p2=j*m/100;
					ans=max(ans,p1+p2);
				}
			}
		}
		cout<<ans<<endl;
	}
}