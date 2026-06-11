#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<double> p(n);
    for(int i=0;i<n;++i) cin>>p[i];
    
    vector<double> e(n+1);
    for(int i=0;i<n;++i){
        double t=p[i];
        e[i+1]=(t+1)/2.0;
    }

    for(int i=0;i<n;++i) e[i+1]+=e[i];

    double ans=0.0;
    for(int i=0;i<n-k+1;++i){
        ans=ans<e[i+k]-e[i]?e[i+k]-e[i]:ans;
    }

    cout<<fixed<<setprecision(10)<<ans<<endl;
}