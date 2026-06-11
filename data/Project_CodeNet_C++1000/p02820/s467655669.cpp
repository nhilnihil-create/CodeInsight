#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N,K,R,S,P;
    string T;
    cin>>N>>K>>R>>S>>P>>T;
    int ans=0;
    for(int i=0;i<K;i++){
                int bef=0;
        for(int j=i;j<N;j+=K){
            //printf("[%d][%c]\n",j,T[j]);
            if(bef==0){
                if(T[j]=='r'){
                    ans+=P;
                    bef=3;
                }
                if(T[j]=='s'){
                    ans+=R;
                    bef=1;
                }
                if(T[j]=='p'){
                    ans+=S;
                    bef=2;
                }
            }
            else if(bef==1){
                if(T[j]=='r'){
                    ans+=P;
                    bef=3;
                }
                if(T[j]=='s'){
                    bef=0;
                }
                if(T[j]=='p'){
                    ans+=S;
                    bef=2;
                }

            }
            else if(bef==2){
                if(T[j]=='r'){
                    ans+=P;
                    bef=3;
                }
                if(T[j]=='s'){
                    ans+=R;
                    bef=1;
                }
                if(T[j]=='p'){
                    bef=0;
                }
            }
            else if(bef==3){
                if(T[j]=='r'){
                    bef=0;
                }
                if(T[j]=='s'){
                    ans+=R;
                    bef=1;
                }
                if(T[j]=='p'){
                    ans+=S;
                    bef=2;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
