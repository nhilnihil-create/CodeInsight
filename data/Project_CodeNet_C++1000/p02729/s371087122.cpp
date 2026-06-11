#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    int c1=0;
    int c2=0;
    
    if(n+m==2)
        cout<<0<<endl;
    else{
        if(n>=2)
            c1=n*(n-1)/2;
        if(m>=2)
            c2=m*(m-1)/2;
        cout<<c1+c2<<endl;
    }
}