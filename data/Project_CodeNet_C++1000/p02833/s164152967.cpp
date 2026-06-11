#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){

    long long int N;
    cin>>N;
    if(N%2ll==1){
        cout<<0<<endl;
        return 0;
    }
    long long int ans=0;
    long long int hatena=2;
    while(1){
        hatena*=5;
        ans+=N/hatena;
        if(N<hatena)break;
    }
    cout<<ans<<endl;
    /*
    long long int ans=0;
    for(long long int i=10;0<i;i-=2){
        if     (i%10000000000==0)ans+=10;
        else if(i%1000000000==0)ans+=9;
        else if(i%100000000==0)ans+=8;
        else if(i%10000000==0)ans+=7;
        else if(i%1000000==0)ans+=6;
        else if(i%100000==0)ans+=5;
        else if(i%10000==0)ans+=4;
        else if(i%1000==0)ans+=3;
        else if(i%100==0)ans+=2;
        else if(i%10==0)ans+=1;
    }
    cout<<ans<<endl;
    */
    return 0;
}
