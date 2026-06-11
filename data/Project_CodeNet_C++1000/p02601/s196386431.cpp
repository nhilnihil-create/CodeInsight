#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,n,i,d=0,e;
    cin>>a>>b>>c;
    cin>>n;
    for(i=1;i<=n;i++){
        if(b>a){
            d=1;
        }
        if(d==0 && b<=a){
            b*=2;
        }
        if(d==1 && c<=b){
            c*=2;
        }
    }
    if(c>b && b>a){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
