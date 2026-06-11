#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin>>N;
    int P[N],Q[N];
    rep(i,N)cin>>P[i];
    rep(i,N)cin>>Q[i];
    int A[N];
    rep(i,N)A[i]=i+1;
    int p=0,q=0;
    int j=0;
    int a=0,b=0;
    do{
        rep(i,N){
            if(A[i]==P[i])p++;
            if(A[i]==Q[i])q++;
        }
        if(p==N)a=j;
        if(q==N)b=j;
        j++;
        p=0;
        q=0;
    }while(next_permutation(A,A+N));
    cout << abs(a-b) <<endl;
    return 0;
}