#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,counter=0,flag=0;
    long long x=1;
    cin>>n;
    m=n;

    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    for(long long int i=2;i*i<=m;i++){
        if(n%i==0){   
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<1<<endl;
        return 0;
        }  

    for(long long int i=2;i*i<=m;i++){
        x=i;
        while(n%x==0){
            counter++;
            n/=x;
            x*=i;
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1){
        counter++;
    }
    cout<<counter<<endl;
    
}