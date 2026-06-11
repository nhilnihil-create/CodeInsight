#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;cin>>N>>M;
    int S[M],C[M];
    for(int i=0;i<M;i++){
        cin>>S[i]>>C[i];
    }
    vector<int>A(N,-1);
    for(int i=0;i<M;i++){
        if(A[S[i]-1]!=-1&&A[S[i]-1]!=C[i]){
            cout<<-1<<endl;
            return 0;
        }
        else{
            A[S[i]-1]=C[i];
        }
    }
    for(int i=0;i<N;i++){
        if(N>1&&A[0]==0){
            cout<<-1<<endl;
            return 0;
        }
        if(A[i]==-1){
            if(i==0){
                if(N!=1){
                    cout<<1;        
                }
                else{
                    cout<<0;
                }
                
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<A[i];
        }
    }
    return 0;
}
