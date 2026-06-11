#include<bits/stdc++.h> 
using namespace std;
int a,b;
int c[200000000];
long long ans;
int main()
{
    cin>>a>>b;
    for(int i=1;i<=b;i++){
    	cin>>c[i];
		ans+=c[i];
	} 
	if(ans>a)cout<<-1;
	else cout<<a-ans;
	return 0;
}
