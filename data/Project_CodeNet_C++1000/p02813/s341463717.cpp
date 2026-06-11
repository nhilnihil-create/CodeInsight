#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N;
int A[8],B[8];
int now[8];
int Aans,Bans;
int use[9];
int cou=0;
void func(int depth){

    if(depth==N){
        int Aflu=1,Bflu=1;
        for(int i=0;i<N;i++){
            if(now[i]!=A[i])Aflu=0;
            if(now[i]!=B[i])Bflu=0;
        }
        if(Aflu==1)Aans=cou;
        if(Bflu==1)Bans=cou;
        cou++;
        return;
    }

    for(int i=1;i<=N;i++){

        if(use[i]==0){
            now[depth]=i;
            use[i]=1;
            func(depth+1);
            use[i]=0;
        }
    }
}
int main(){

    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<N;i++)cin>>B[i];
    func(0);
    cout<<abs(Aans-Bans)<<endl;
    return 0;
}
