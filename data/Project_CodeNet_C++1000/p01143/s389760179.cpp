#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    while(1){
        int N, M, P;
        cin>> N>> M>> P;
        if(!(N||M||P)) break;
        int X[N];
        for(int i=0; i<N; i++) cin>> X[i];

        int s=100*accumulate(X, X+N, 0);
        int haito=s/100*(100-P);

        cout<< (X[M-1]==0? 0: haito/X[M-1])<< endl;
    }
    
    return 0;
}