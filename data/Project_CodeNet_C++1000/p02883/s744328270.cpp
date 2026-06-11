#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N,K;
    long long int i;
    cin >> N >> K;
    long long int A[N],F[N];
    long long int MAX=1e12+10;
    long long int MIN=0;
    long long int MID;
    long long int k;
    long long int sum=0;
    int flag;
    for(i=0;i<N;i++){
        cin >> A[i];
        sum+=A[i];
    }
    if(sum<=K)cout << 0 << endl;
    else{
    for(i=0;i<N;i++)cin >> F[i];
    sort(A,A+N);
    sort(F,F+N);
    long long int B[N];
    for(i=0;i<N;i++)B[i]=A[i]*F[N-i-1];    
    while(MAX-MIN>1){
        k=0;
        flag=0;
        MID=(MAX+MIN)/2;
        for(i=0;i<N;i++){
            if(B[i]>MID)k+=(A[i]-(MID/F[N-i-1]));
            if(k>K){
                flag++;
                break;
            }
        }
        if(flag>0)MIN=MID;
        else{MAX=MID;}
    }
    cout << MAX << endl;
}}