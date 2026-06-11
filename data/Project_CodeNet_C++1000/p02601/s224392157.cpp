#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(c>b&&b>a)cout<<"Yes";
	else{
		bool e=0;
		for(int i=1;i<=d;i++){
			if(b>=c){
				c*=2;
				continue;
			}
			if(a>=b){
				b*=2;
				continue;
			}
			cout<<"Yes";
			e=1;
			break;
		}
		if(c>b&&b>a&&e==0)cout<<"Yes";
		else if(e==0)
		cout<<"No";
	}
	return 0;
}