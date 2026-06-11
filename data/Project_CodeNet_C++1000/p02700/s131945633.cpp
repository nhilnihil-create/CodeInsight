#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=0;
	while(1){
		x++;
		if(x%2==1){
			c-=b;
		}
		else{
			a-=d;
		}
		if(a<=0){
			cout<<"No";
			return 0;
		}
		if(c<=0){
			cout<<"Yes";
			return 0;
		}
	}	
	return 0;
}