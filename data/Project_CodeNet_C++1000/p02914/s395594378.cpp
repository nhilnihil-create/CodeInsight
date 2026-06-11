#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll a[N];
ll ans,sum;int n;
struct xxj{
	ll p[100];
	void built(){
    	for(int i=1;i<=n;i++)
    	for(int j=60;j>=0;j--){
        	if((a[i]>>j)&1){
            	if(p[j]==0){p[j]=a[i];break;}
     	    	else a[i]^=p[j];
        	}
    	}
	}
	void cl(){
		for(int i=60;i>=0;i--){
			if(ans+(ans^sum)<(ans^p[i])+(ans^p[i]^sum))ans^=p[i];
		}
	}	
}T;
int main()
{
	scanf("%d",&n);sum=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum^=a[i];
	for(int i=0;i<60;i++){
		if((sum>>i)&1){
			for(int j=1;j<=n;j++){
				if((a[j]>>i)&1)a[j]^=(1ll<<i);
			}
		}
	}
	T.built();
	T.cl();
	cout<<ans+(sum^ans)<<endl;
	return 0;
}