#include<bits/stdc++.h>
using namespace std;

int main(){
    bool flg=true;
    int N,i,a=0,b=0;
    cin>>N;
    vector<int>P(N),Q(N),Pc(N),A(N);
    for(i=0;i<N;i++)cin>>P[i];P[i]=Pc[i];
    for(i=0;i<N;i++)cin>>Q[i];
    for(i=1;i<=N;i++)A[i-1]=i;

    do{
        for(i=0;i<N;i++)if(A[i]!=P[i])flg=false;
        if(flg)break;
        flg=true;
        a++;
    }while(next_permutation(A.begin(),A.end()));

    for(i=1;i<=N;i++)A[i-1]=i;
    do{
        for(i=0;i<N;i++)if(A[i]!=Q[i])flg=false;
        if(flg)break;
        flg=true;
        b++;
    }while(next_permutation(A.begin(),A.end()));

    cout<<abs(a-b)<<endl;
}