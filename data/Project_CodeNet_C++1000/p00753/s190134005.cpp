#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=1e-10;
const ll INF=1000000000;
int main(){
    int prime[300000];
    for(int i=0;i<300000;i++){
        prime[i]=1;
    }
    prime[1]=0;prime[0]=0;
    for(int i=2;i<=150000;i++){
        if(prime[i]==1){
            for(int j=i+i;j<=300000;j+=i){
                prime[j]=0;
            }
        }
    }
    int c[300000]={};
    for(int i=1;i<300000;i++){
        c[i]=c[i-1]+prime[i];
    }
    int n;
    while(cin>>n,n){
        cout<<c[2*n]-c[n]<<endl;
    }
    return 0;
}
