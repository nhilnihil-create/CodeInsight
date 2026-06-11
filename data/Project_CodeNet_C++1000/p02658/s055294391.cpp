#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf ll(1e18)
int main()
{
	int n;
	cin>>n;
	ll pr=1;
	int flag=0;
	for(int i=0; i<n; i++){
		ll num;
		cin>>num;
		ll var=inf/pr;
		if(num==0){
			pr=0;
			flag=0;
			break;
		}
		if(num>var){
			flag=1;
		}
		else if(flag==0)
		 pr*=num;
	}
	if(flag)
	 cout<<"-1";
	else
	 cout<<pr;
	return 0;
	
}