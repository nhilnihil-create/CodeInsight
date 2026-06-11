#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<double> p(n),v(n);
    for(int i=0;i<n;i++){
        double a;
        cin>>a;
        p[i]=(a+1)/2;
    }

    double ans=0;
    v[0]=p[0];
    for(int i=1;i<n;i++){
        v[i]=v[i-1]+p[i];
    }
    for(int i=0;i<n-k;i++){
        ans=max(ans,v[i+k]-v[i]);
    }
    if(n==k) ans=v[n-1];
    printf("%.10f\n",ans);
}