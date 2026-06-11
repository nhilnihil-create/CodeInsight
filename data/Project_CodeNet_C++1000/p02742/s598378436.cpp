#include<iostream>
#include<math.h>
#include<string>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    long long H,W;
    cin>>H>>W;
    if(H==1 || W==1){
        cout<<'1';
        return 0;
    }else{
        ;
    }
    if((H*W)%2==0){
        cout<<(H*W)/2;
        return 0;
    }else{
        cout<<((H*W)+1)/2;
    }
    return 0;
}
