#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K,C;
    cin>>N>>K>>C;
    string S;
    cin>>S;
    int dp1[N+10],dp2[N+10],lastI=1000000000;
    dp1[N]=0;
    for(int i=N-1;i>=0;i--){
        if(lastI-i>C && S.at(i)=='o'){
            lastI=i;
            dp1[i]=dp1[i+1]+1;
        }
        else{
            dp1[i]=dp1[i+1];   
        }
    }
    lastI=-1000000000;
    for(int i=0;i<N;i++){
        if(i-lastI>C && S.at(i)=='o'){
            lastI=i;
            if(i==0){
                dp2[i]=1;
            }
            else{
                dp2[i]=dp2[i-1]+1;
            }
        }
        else{
            dp2[i]=dp2[i-1];   
        }
    }
    for(int i=0;i<N;i++){
        if(i==0){
            if(dp1[i+1]<K){
                cout<<i+1<<endl;
            }
        }
        else if(i==N-1){
            if(dp2[i-1]<K){
                cout<<i+1<<endl;
            }
        }
        else{
            if(dp1[i+1]+dp2[i-1]<K){
                cout<<i+1<<endl;
            }
        }
    }
}