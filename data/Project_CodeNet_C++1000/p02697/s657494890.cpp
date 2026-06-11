#include<bits/stdc++.h>
using namespace std;

long long n,m;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	
	if(n%2==1)
	for(int i=0;i<m;i++){
		cout<<(i+1)<<" "<<n-1-i<<"\n";
	}
	else{
		
		int tmp=(n/2-1);
		
		for(int i=0;i<tmp;i+=2){
			cout<<1+i/2<<" "<<1+tmp-int(tmp%2==0)-i/2<<"\n";
			m--;
			if(m==0)break;
		}
		
		for(int i=1;i<tmp;i+=2){
			if(m==0)break;
			cout<<n-(i-1)/2<<" "<<n-(tmp-tmp%2)+(i-1)/2<<"\n";
			m--;
		}
	}

return 0;
}
