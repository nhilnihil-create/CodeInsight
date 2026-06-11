#include<bits/stdc++.h>
using namespace std;

int winner(int n,int p);

int main(){
    int n,p;
    while(1){
        cin>>n>>p;
        if(n==0 && p==0)break;

        int ans=winner(n,p);

        cout<<ans<<endl;
    }

    return 0;
}


int winner(int n,int p){

    int cand[n];    for(int i=0;i<n;i++)cand[i]=0;
    int stoneSum=p;

    int step=0;
    int winnerNum=-1;
    while(winnerNum<0){
        for(int i=0;i<n;i++){
            if(cand[i]==stoneSum){
                winnerNum=i;
                break;
            }

            if(p>0){
                cand[i]++;
                p--;
                continue;
            }else{
                p+=cand[i];
                cand[i]=0;
                continue;
            }
        }

    }
    return winnerNum;

}

