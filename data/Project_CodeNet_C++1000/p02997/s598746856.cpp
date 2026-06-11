#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    if(K>(N-1)*(N-2)/2){
        cout<<-1<<endl;
    }
    else{
        cout<<N-1+(N-1)*(N-2)/2-K<<endl;
        for(int i=0;i<N-1;i++){
            cout<<1<<" "<<i+2<<endl;
        }
        int count=0; 
        int s=2;
        while(count<(N-1)*(N-2)/2-K){
            for(int i=s+1;i<=N;i++){
                cout<<s<<" "<<i<<endl;
                count++;
                if(count==(N-1)*(N-2)/2-K){
                    return 0;
                }
            }
            s++;
        }
    }
}