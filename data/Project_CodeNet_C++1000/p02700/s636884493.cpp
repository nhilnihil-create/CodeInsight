#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(false);
	int a,b,c,d,i;
	cin>>a>>b>>c>>d;
	while(a>=0&&c>=0){
		c-=b;
		if(c<=0){
			cout<<"Yes";
			break;
		}
		a-=d;
		if(a<=0){
			cout<<"No";
			break;
		}
	}
	return 0;
}
