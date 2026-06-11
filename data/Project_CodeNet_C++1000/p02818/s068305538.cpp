#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    ll A,B,K;
    cin>>A>>B>>K;
    if(K>A){
        
        K-=A;
        A=0;
    }
    else{
        A-=K;
        K=0;
    }
    
    if(K>B){
        B=0;
    }
    else{
        B-=K;
    }
        
        cout<<A<<' '<<B<<endl;
    }
    
    

