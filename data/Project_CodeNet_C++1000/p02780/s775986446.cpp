#include <bits/stdc++.h>
using namespace std;

double SUM(int p){
	return (1.0+p)/2.0;
}
int main(){
	int n,k;
    double ans=0.0;
    cin>>n>>k;
    double p[n+1];
    p[0]=0.0;
    for(int i=1;i<=n;i++){
        int q;
        cin>>q;
        p[i]=p[i-1]+SUM(q);
    }
    for(int i=0;i<=n-k;i++){
    	ans=max(ans,p[i+k]-p[i]);
    }
    cout<<setprecision(16)<<ans;
}