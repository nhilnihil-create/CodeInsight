#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int n,x[100],y[100];
    double sum[4];
    cin >> n;
    for(int i=0;i<n;i++) cin >> x[i];
    for(int j=0;j<n;j++) cin >> y[j];
    for(int k=0;k<4;k++) sum[k] = 0.0;
    for(int p=1;p<4;p++){
        for(int i=0;i<n;i++){
            sum[p] += pow(fabs(x[i]-y[i]),p);
        }
        sum[p] = pow(sum[p],1.0/p);
    }
    for(int i=0;i<n;i++){
        sum[0] = (sum[0]<fabs(x[i]-y[i])?fabs(x[i]-y[i]):sum[0]);
    }
    printf("%.5f\n%.5f\n%.5f\n%.5f\n",sum[1],sum[2],sum[3],sum[0]);
    return 0;
}
