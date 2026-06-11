#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n;
    double a[1000];
    double b[1000];
    double sum[5]={0,0,0,0,0};
    double ans[5]={0,0,0,0,0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        sum[1] += abs(a[i]-b[i]);
    }
    for(int i=0;i<n;i++){
        sum[2] += pow(a[i]-b[i],2);
    }
    for(int i=0;i<n;i++){
        sum[3] += pow(abs(a[i]-b[i]),3);
    }
    for(int i=0;i<n;i++){
        sum[4]=max(sum[4],abs(a[i]-b[i]));
    }
    for(int i=1;i<=3;i++){
        ans[i]=pow(sum[i],1.0*1/i);
    }
    ans[4]=sum[4];
    for(int i=1;i<=4;i++){
        cout<<fixed<<setprecision(30)<<ans[i]<<endl;
    }
    return 0;
}