#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c;
	cin>>a>>b>>c;
	int k;
	cin>>k;
	
		while(a>=b){
			b*=2;
			--k;
		}
		if(k<0){
			cout<<"NO";
			return 0;
		}
		while(b>=c){
			c*=2;
			--k;
		}
		if(k<0){
			cout<<"No";
			return 0;
		}
		cout<<"Yes";
	return 0;
}