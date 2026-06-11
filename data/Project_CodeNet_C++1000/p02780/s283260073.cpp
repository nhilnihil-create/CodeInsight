#include <bits/stdc++.h>
using namespace std;
 
double SUM(double p){
	double a=0;
    for(int i=1;i<=p;i++) a+=i;
    return a/p;
}
int main(){
	int n,k;
    double ans=0;
    cin>>n>>k;
    double p[n];
    for(int i=0;i<n;i++){
        double q;
        cin>>q;
        p[i]=SUM(q);
    }
    for(int i=0;i<k;i++) ans+=p[i];
    double sum=ans;
    for(int i=0;i<=n-k;i++){
        sum=sum+p[i+k]-p[i];
    	ans=max(sum,ans);
    }
    cout<<setprecision(16)<<ans;
}
