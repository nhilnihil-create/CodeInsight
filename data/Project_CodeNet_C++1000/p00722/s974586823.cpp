#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	bool dt[1000000];
	rep(i,1000000)dt[i]=true;
	dt[0]=dt[1]=false;
	loop(i,2,1000000){
		for(int j=2;i*j<1000000;j++){
			dt[i*j]=false;
		}
	}
	long long a,ans;
	int d,n;
	while(1){
		cin>>a>>d>>n;
		if(a==0 && d==0 && n==0)break;
		long long cnt=0;
		for(long long i=0;i<1000000;i++){
			long long alt=a+d*i;
			if(dt[alt])cnt++;
			if(cnt==n){
				ans=alt;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}