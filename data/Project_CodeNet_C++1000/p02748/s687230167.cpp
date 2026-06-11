#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int A,B,M,priceA,priceB,priceC;
    cin>>A>>B>>M;
    int a[A],b[B],x[M],y[M],c[M];
    for(int i=0;i<A;i++){
        cin>>a[i];
    }
    for(int i=0;i<B;i++){
        cin>>b[i];
    }
    for(int i=0;i<M;i++){
        cin>>x[i]>>y[i]>>c[i];
    }
    for(int i=0;i<A;i++){
        if(i==0){
            priceA=a[0];
        }
        else{
            priceA=min(priceA,a[i]);
        }
    }
    for(int i=0;i<B;i++){
        if(i==0){
            priceB=b[0];
        }
        else{
            priceB=min(priceB,b[i]);
        }
    }
    for(int k=0;k<M;k++){
        if(k==0){
            priceC=a[x[0]-1]+b[y[0]-1]-c[0];
        }
        else{
            priceC=min(priceC,a[x[k]-1]+b[y[k]-1]-c[k]);
        }
    }
    cout<<min(priceA+priceB,priceC)<<endl;
    return 0;
}
