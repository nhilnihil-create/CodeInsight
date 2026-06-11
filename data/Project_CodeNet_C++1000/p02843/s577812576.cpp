#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll= long long;
using namespace std;

int main(){
    int X;
    cin>>X;
    int N=X/100;
    bool flag=false;
    rep(i,N+1){
        int rest=X-i*100;
        if(rest>=0&&rest<=5*i){
            flag=true;
            break;
        }
    }
    if(flag==true){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    
    
    }
    
    
  
 
 


