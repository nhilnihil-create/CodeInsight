#include<iostream>
using namespace std;

int gcd(int m,int n){
    if(n==0)
    return m;

    return gcd(n,m%n);
}

int main(){
    int k;
    cin>>k;
    int ans=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                int a=gcd(i,j);
                ans+=gcd(a,l);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}