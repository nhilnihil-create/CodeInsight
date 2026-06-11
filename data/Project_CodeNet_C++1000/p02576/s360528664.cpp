#include<bits/stdc++.h>
using namespace std;
int main(){
    double s,x,t;
    int q=0;
    cin>>s>>x>>t;
    double p=s/x;
    if(int(s)%int(x)>0){
        q=(int(s)/int(x))+1;
    }
    else{
        q=(int(s)/int(x));
    }
    long int r=q*t;
    cout<<r;
}