#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    cin>>n;
    while(n>=1000){
        n=n%1000;
    }
    if(n==0){
        cout<<"0"<<"\n";
    }else{
        cout<<1000-n<<"\n";
    }
    return(0);
}