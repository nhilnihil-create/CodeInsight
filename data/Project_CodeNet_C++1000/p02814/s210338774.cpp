#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    while(x){
        y%=x;
        if(y==0)break;
        x%=y;
    }
    return x+y;
}
int main(){
    int n,m;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    long long lcm=a[0]/2;
    for(int i=1;i<n;i++){
        lcm*=a[i]/2/gcd(lcm,a[i]/2);
        if(lcm>m){
            cout<<"0"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(lcm%a[i]==0){
            cout<<"0"<<endl;
            return 0;
        }
    }
    cout<<(m+lcm)/lcm/2<<endl;
    return 0;
}