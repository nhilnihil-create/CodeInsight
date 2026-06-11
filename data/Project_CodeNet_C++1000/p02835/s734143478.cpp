#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    ll A,sum=0;
    
    rep(i,3){
        cin>>A;
        sum+=A;
    }
    if(sum>21){
        cout<<"bust"<<endl;
    }
    else{
        cout<<"win"<<endl;
    }

}


