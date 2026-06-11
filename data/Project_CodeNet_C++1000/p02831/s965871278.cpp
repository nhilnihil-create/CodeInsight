#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	for(long long ans=a;ans<=(long long)a*b;ans+=a){
		if(ans%b==0){
			cout<<ans<<endl;
			return 0; 
		}
	}
	return 0;
}