#include <bits/stdc++.h>
using namespace std;


int main(void){
    
    int N;
    int K;
    long long S;
    
    cin >> N >> K >> S;
    if(S!=1000000000){
        if(N!=K){
            for(int i = 0; i < K;i++)cout << S <<" ";
            for(int i = K; i < N-1;i++)cout << S+1 <<" ";
            cout << S+1 <<endl;
        }else{
            for(int i = 0; i < N - 1;i++)cout << S <<" ";
            cout << S <<endl;
        }
    }else{
        if(N!=K){
            for(int i = 0; i < K;i++)cout << S <<" ";
            for(int i = K; i < N-1;i++)cout << 1 <<" ";
            cout << 1 <<endl;
        }else{
            for(int i = 0; i < N - 1;i++)cout << S <<" ";
            cout << S <<endl;
        }
    }
    
}
