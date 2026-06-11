#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    int ansN=0,anslis[30000][2]={0};
    int topa=0;
    if(((N-1)*(N-2))/2<K){
        puts("-1");
        return 0;
    }
    else{
        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                if(topa==K||j==N){
                    anslis[ansN][0]=i,anslis[ansN][1]=j;
                    ansN++;
                }
                else{
                    topa++;
                }
            }
        }
    }
    cout<<ansN<<endl;
    for(int i=0;i<ansN;i++)cout<<anslis[i][0]<<" "<<anslis[i][1]<<endl;
    return 0;
}
